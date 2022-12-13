/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:53 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/10 17:50:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_arg	*init_arg(char **argv, char **env)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->env = env;
	arg->file1 = argv[1];
	arg->file2 = argv[4];
	arg->cmd1 = ft_split(argv[2], " ");
	arg->cmd2 = ft_split(argv[3], " ");
	arg->cmd1[0] = ft_get_path(arg, arg->cmd1[0]);
	arg->cmd2[0] = ft_get_path(arg, arg->cmd2[0]);
	if (!arg->cmd1[0] || !arg->cmd2[0])
		return (NULL);
	return (arg);
}

char	*ft_get_path(t_arg *arg, char *cmd)
{
	char	**paths;
	char	*temp;
	char	*current_path;
	int		i;

	paths = ft_split(get_all_path(arg->env), ":");
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		current_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(current_path, F_OK) == 0)
			break ;
		free(current_path);
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(cmd);
	return (current_path);
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
