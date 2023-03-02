/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:11:47 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/15 15:42:44 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*A function which count the number of sub-strings*/
int	ft_count_strings(char *cmd)
{
	int	i;
	int	strings_count;

	i = 0;
	strings_count = 1;
	while (cmd[i])
	{
		while (cmd[i] != '\'' && cmd[i] != '"' && cmd[i] != ' ' && cmd[i])
			i++;
		while (cmd[i] == ' ' && cmd[i])
		{
			i++;
			if (cmd[i] != ' ' || !cmd[i])
				strings_count++;
		}
		if (cmd[i] == '\'' || cmd[i] == '"')
		{
			i++;
			while (cmd[i] != '\'' && cmd[i] != '"')
				i++;
			i++;
		}
	}
	return (strings_count);
}

/*A function which fill a 2D array*/
char	**ft_fill_stack(char *cmd, char **split_cmd, int i)
{
	int	save;
	int	index;

	save = 0;
	index = 0;
	while (cmd[i])
	{
		while (cmd[i] == ' ' && cmd[i])
			i++;
		save = i;
		while (cmd[i] != '\'' && cmd[i] != '"' && cmd[i] != ' ' && cmd[i])
			i++;
		if (cmd[i] == '\'' || cmd[i] == '"')
		{
			while (cmd[++i] != '\'' && cmd[i] != '"')
				;
			i++;
		}
		if (i != save)
			split_cmd[index] = ft_rm_quotes(ft_substr(cmd, save, i - save));
		if (!split_cmd[index++])
			return (ft_free_tab(split_cmd), NULL);
	}
	split_cmd[index] = NULL;
	return (split_cmd);
}

/*A function which create and fill a 2D array*/
char	**ft_split_cmd(char	*cmd)
{
	char	**split_cmd;

	split_cmd = malloc(sizeof(char *) * (ft_count_strings(cmd) + 1));
	if (!split_cmd)
		return (NULL);
	split_cmd = ft_fill_stack(cmd, split_cmd, 0);
	return (split_cmd);
}
