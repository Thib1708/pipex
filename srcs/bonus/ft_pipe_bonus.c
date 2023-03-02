/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:44:34 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/02 10:34:15 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

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

int	ft_heredoc(t_pipex *args)
{
	char	*line;
	int		fd[2];

	if (args->here_doc)
	{
		if (pipe(fd) == -1)
			return (ft_perror("pipe"));
		while (1)
		{
			write (1, "heredoc>", 8);
			get_next_line(1, &line);
			if (!ft_strncmp(line, args->limiter, ft_strlen(line)))
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		free(line);
		args->fdd = fd[0];
		close(fd[1]);
	}
	return (0);
}

int	ft_pipe(t_pipex *args)
{
	int		fd[2];
	pid_t	pid;

	if (ft_heredoc(args))
		return (1);
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
