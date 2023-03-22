/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:44:34 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/22 13:58:33 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	ft_exec(t_pipex *args, int fd[2], int i)
{
	if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_perror("dup2"));
	if (args->cmds[i + 1] != NULL)
	{
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (ft_perror("dup2"));
	}
	close(fd[0]);
	args->cmds[i][0] = ft_get_path(args, args->cmds[i][0]);
	if (!args->cmds[i][0])
		return (0);
	if (execve(args->cmds[i][0], args->cmds[i], args->envp) == -1)
	{
		close(fd[1]);
		return (0);
	}
	return (1);
}

int	ft_wait_execution(t_pipex *args)
{
	int	i;

	i = args->size - 1;
	while (i >= 0)
	{
		waitpid(args->pid_tab[i], NULL, 0);
		close(args->close_tab[i]);
		i--;
	}
	return (0);
}

int	ft_add_pid(t_pipex *args, pid_t pid)
{
	int	i;

	i = 0;
	while (args->pid_tab[i] != 0 && i < args->size)
		i++;
	if (i < args->size)
	{
		args->pid_tab[i] = pid;
		args->close_tab[i] = args->fdd;
	}
	return (0);
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
		close(fd[1]);
		ft_add_pid(args, pid);
		args->fdd = fd[0];
	}
	return (0);
}
