/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:44:34 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/07 11:24:34 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	ft_exec(t_pipex *args, int fd[2], int i)
{
	if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_perror("dup2"));
	if (args->cmds[i + 1] != NULL)
	{
		if (dup2(fd[1], 1) == -1)
			return (ft_perror("dup2"));
	}
	close(fd[0]);
	args->cmds[i][0] = ft_get_path(args, args->cmds[i][0]);
	if (!args->cmds[i][0])
		return (0);
	if (execve(args->cmds[i][0], args->cmds[i], args->envp) == -1)
		return (0);
	return (1);
}

int	ft_pipe(t_pipex *args)
{
	int		fd[2];
	pid_t	pid;

	if (dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_perror("dup2"));
	while (args->cmds[++args->i] != NULL)
	{
		if (pipe(fd) == -1)
			return (ft_perror("pipe"));
		pid = fork();
		if (pid == -1)
			return (ft_perror("pipe"));
		else if (pid == 0)
			if (!ft_exec(args, fd, args->i))
				return (1);
		waitpid(pid, NULL, 1);
		args->fdd = fd[0];
		close(fd[1]);
	}
	return (0);
}
