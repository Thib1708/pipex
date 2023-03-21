/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:11:47 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/14 18:12:08 by thibaultgir      ###   ########.fr       */
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
	if (cmd[0] == ' ' && !cmd[1])
		return (0);
	while (cmd[i])
	{
		while (cmd[i] != '\'' && cmd[i] != '"' && cmd[i] != ' ' && cmd[i])
			i++;
		while (cmd[i] == ' ' && cmd[i++])
			if (cmd[i] != ' ' || !cmd[i])
				strings_count++;
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
	int		malloc_size;

	malloc_size = ft_count_strings(cmd);
	if (malloc_size == 0)
	{
		split_cmd = malloc(sizeof(char *) * 2);
		if (!split_cmd)
			return (NULL);
		split_cmd[0] = ft_strdup(" ");
		split_cmd[1] = NULL;
		return (split_cmd);
	}
	split_cmd = malloc(sizeof(char *) * (malloc_size + 1));
	if (!split_cmd)
		return (NULL);
	split_cmd = ft_fill_stack(cmd, split_cmd, 0);
	return (split_cmd);
}

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
		return (ft_printf_fd(STDERR_FILENO, "Error parse quote\n"), 0);
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
	if (!cmd)
		return (NULL);
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
	return (free(cmd), new_cmd);
}
