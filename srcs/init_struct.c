/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:53 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/06 20:33:24 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_arg	*init_arg(char **argv, char **env)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	arg->file1 = argv[1];
	arg->file2 = argv[4];
	arg->cmd1 = ft_split(argv[2], " ");
	arg->cmd2 = ft_split(argv[3], " ");
	arg->path1 = get_path(env, arg->cmd1[0]);
	arg->path2 = get_path(env, arg->cmd2[0]);
	arg->env = env;
	if (!arg->path1 || !arg->path2 || !arg->cmd1 || !arg->cmd2)
		return (NULL);
	return (arg);
}

char	*get_path(char **env, char *cmd)
{
	char	**path;
	char	*temp;
	char	*current_path;
	int		i;

	i = 0;
	path = ft_split(get_all_path(env), ":");
	if (!path)
		return (NULL);
	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		free(*path);
		current_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(current_path, F_OK) == 0)
		{
			while (*path++)
				free(*path);
			return (current_path);
		}
		free(current_path);
		path++;
	}
	ft_printf("zsh: command not found: %s", cmd);
	return (NULL);
}

char	*get_all_path(char **env)
{
	while (*env)
	{
		if (ft_strnstr(*env, "PATH", ft_strlen(*env)))
			return (*env + 5);
		env++;
	}
	return (NULL);
}
