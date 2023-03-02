/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:53 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/21 16:28:51 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*A function to fill the struct*/
t_arg	*init_arg(char **argv, char **env)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->env = env;
	arg->infile = argv[1];
	arg->outfile = argv[4];
	if (!ft_check_quotes(argv[2], '"') || !ft_check_quotes(argv[2], '\''))
		return (NULL);
	arg->cmd1 = ft_split_cmd(argv[2]);
	if (!ft_check_quotes(argv[3], '"') || !ft_check_quotes(argv[3], '\''))
		return (NULL);
	arg->cmd2 = ft_split_cmd(argv[3]);
	if (!arg->cmd1 || !arg->cmd2)
		return (NULL);
	arg->cmd1[0] = ft_get_path(arg, arg->cmd1[0]);
	if (!arg->cmd1[0])
		return (NULL);
	arg->cmd2[0] = ft_get_path(arg, arg->cmd2[0]);
	if (!arg->cmd2[0])
		return (NULL);
	return (arg);
}

/*A function which found, if it does exist, the right path*/
char	*ft_get_path(t_arg *arg, char *cmd)
{
	char	**paths;
	char	*temp;
	char	*current_path;
	int		i;

	if (access(cmd, F_OK) == 0)
		return (cmd);
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
		current_path = NULL;
	}
	ft_free_tab(paths);
	if (current_path == NULL)
		return (ft_printf("pipex: %s: command not found\n", cmd), cmd);
	return (free(cmd), current_path);
}

/*A function which founds all the path of the env*/
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

/*A function which check if quotes are closed*/
int	ft_check_quotes(char *cmd, char type_quote)
{
	int	i;
	int	nb_quotes;

	i = -1;
	nb_quotes = 0;
	if (!cmd)
		return (0);
	while (cmd[++i])
	{
		if (cmd[i] == type_quote)
			nb_quotes++;
	}
	if (nb_quotes % 2 != 0)
		return (ft_printf("Error parse quote\n"), 0);
	return (1);
}

/*A function which remove the quotes*/
char	*ft_rm_quotes(char *cmd)
{
	int		i;
	int		j;
	int		malloc_size;
	char	*new_cmd;

	malloc_size = 0;
	i = -1;
	while (cmd[++i])
		if (cmd[i] != '"' && cmd[i] != '\'')
			malloc_size++;
	new_cmd = malloc(sizeof(char) * (malloc_size + 1));
	if (!new_cmd)
		return (NULL);
	i = 0;
	j = 0;
	while (cmd[j])
	{
		if (cmd[j] == '"' || cmd[j] == '\'')
			j++;
		new_cmd[i++] = cmd[j++];
	}
	new_cmd[i] = '\0';
	free(cmd);
	return (new_cmd);
}
