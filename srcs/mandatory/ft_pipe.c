/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:02:31 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/09 16:19:58 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*A function which redirect the input and execute the first command*/
int	ft_child(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->infile, O_RDONLY);
	if (fd == -1)
		return (ft_perror(arg->infile));
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		return (ft_perror("dup2"));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (ft_perror("dup2"));
	close(fds[0]);
	if (execve(arg->cmd1[0], arg->cmd1, arg->env) == -1)
		return (1);
	return (0);
}

/*A function which redirect the output and execute the second command*/
int	ft_parent(t_arg *arg, int *fds)
{
	int	fd;

	fd = open(arg->outfile, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		return (ft_perror(arg->outfile));
	if (dup2(fds[0], STDIN_FILENO) == -1)
		return (ft_perror("dup2"));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (ft_perror("dup2"));
	close(fds[1]);
	if (execve(arg->cmd2[0], arg->cmd2, arg->env) == -1)
		return (1);
	return (0);
}

/*A function which handle the execution of the 2 commands*/
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
	if (pid1 == 0 && arg->cmd1[0])
		if (ft_child(arg, fds))
			return (1);
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0 && arg->cmd2[0])
		if (ft_parent(arg, fds))
			return (1);
	waitpid(pid1, NULL, 1);
	waitpid(pid2, NULL, 1);
	close(fds[0]);
	close(fds[1]);
	return (0);
}
