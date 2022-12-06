/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:10:02 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/06 20:39:49 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->file1, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("zsh: no such file or directory: %s", arg->file1);
		return (-1);
	}
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		return (-1);
	close(fds[0]);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (execve(arg->path1, arg->cmd1, arg->env))
		return (-1);
	close(fd);
	return (0);
}

int	ft_parent(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->file2, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	if (dup2(fds[0], STDIN_FILENO) == -1)
		return (-1);
	close(fds[1]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (-1);
	if (execve(arg->path2, arg->cmd2, arg->env) == -1)
		return (-1);
	close(fd);
	return (0);
}

int	ft_pipe(t_arg *arg)
{
	int		fds[2];
	int		pid1;
	int		pid2;

	if (pipe(fds) == 1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
		if (ft_child(arg, fds) == -1)
			return (-1);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		if (ft_parent(arg, fds) == -1)
			return (-1);
	waitpid(pid1, NULL, 1);
	waitpid(pid2, NULL, 1);
	close(fds[0]);
	close(fds[1]);
	return (0);
}
