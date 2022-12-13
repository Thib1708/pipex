/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:02 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/10 17:33:58 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->file1, O_RDONLY);
	if (fd == -1)
	{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
			{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	close(fds[0]);
	if (execve(arg->cmd1[0], arg->cmd1, arg->env) == -1)
			{
		perror("\033[31mError\033[0m");
		exit(1);
	}
}

void	ft_parent(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->file2, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	if (dup2(fds[0], STDIN_FILENO) == -1)
	{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("\033[31mError\033[0m");
		exit(1);
	}
	close(fds[1]);
	if (execve(arg->cmd2[0], arg->cmd2, arg->env) == -1)
	{
		perror("\033[31mError\033[0m");
		exit(1);
	}
}

int	ft_pipe(t_arg *arg)
{
	int		fds[2];
	int		pid1;
	int		pid2;

	if (pipe(fds) == 1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
		ft_child(arg, fds);
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
		ft_parent(arg, fds);
	waitpid(pid1, NULL, 1);
	waitpid(pid2, NULL, 1);
	return (0);
}
