/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:41:28 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/28 12:18:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	***ft_fill_cmds(t_pipex *args, char **argv, int argc, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 1;
	while (argc - 1 > k)
		if (argv[k++][0] == '\0')
			return (NULL);
	args->cmds = malloc(sizeof(char **) * (argc - 1));
	if (!args->cmds)
		return (NULL);
	while (argc - 1 > i)
	{
		args->cmds[j] = ft_split(argv[i++], " ");
		if (!args->cmds[j])
			return (free(args->cmds), NULL);
		if (!args->cmds[j][0])
		{
			args->cmds[j + 1] = NULL;
			return (ft_free_stack(args->cmds), NULL);
		}
		j++;
	}
	args->cmds[j] = NULL;
	return (args->cmds);
}

int	ft_fill_struct(t_pipex *args, char **argv, int argc)
{
	int	i;

	i = 1;
	args->size = argc - 3;
	args->fdd = open(argv[i++], O_RDONLY);
	if (args->fdd == -1)
	{
		ft_perror(argv[i - 1]);
		args->fdd = 1;
		args->i++;
		args->size--;
	}
	args->pid_tab = ft_calloc(sizeof(pid_t), (args->size + 1));
	if (!args->pid_tab)
		return (0);
	args->close_tab = ft_calloc(sizeof(pid_t), (args->size + 1));
	if (!args->close_tab)
		return (free(args->pid_tab), 0);
	args->outfile = open(argv[argc -1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	return (i);
}

t_pipex	*ft_init_struct(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	*args;

	args = malloc(sizeof(t_pipex));
	if (!args)
		return (NULL);
	args->envp = envp;
	args->i = -1;
	i = ft_fill_struct(args, argv, argc);
	if (!i)
		return (free(args), NULL);
	args->cmds = ft_fill_cmds(args, argv, argc, i);
	if (!args->cmds)
		return (free(args->close_tab), free(args->pid_tab), close(args->fdd), \
		close(args->outfile), free(args), NULL);
	return (args);
}

char	*ft_get_path(t_pipex *arg, char *cmd)
{
	char	**paths;
	char	*current_path;
	int		i;

	if (ft_check_cmd(cmd))
		return (cmd);
	if (access(cmd, F_OK) == 0)
		return (cmd);
	paths = ft_split(get_all_path(arg->envp), ":");
	if (!paths)
		return (ft_cmd_not_found(cmd), cmd);
	i = -1;
	while (paths[++i])
	{
		current_path = ft_join_mlt(3, paths[i], "/", cmd);
		if (access(current_path, F_OK) == 0)
			break ;
		free(current_path);
		current_path = NULL;
	}
	if (!current_path)
		return (ft_cmd_not_found(cmd), ft_free_tab(paths), cmd);
	return (free(cmd), ft_free_tab(paths), current_path);
}

char	*get_all_path(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH=", 5))
			return (*env + 5);
		env++;
	}
	return (NULL);
}
