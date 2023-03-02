/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:13:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/14 16:24:28 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count(const char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_strrchr(charset, str[i]) && str[i])
			i++;
		while (ft_strrchr(charset, str[i]) == NULL && str[i])
		{
			i++;
			if (ft_strrchr(charset, str[i]) || !str[i])
				count++;
		}
	}
	return (count);
}

static void	free_all_strings(char ***strings)
{
	while (*strings)
	{
		free(*strings++);
	}
	free(strings);
}

static char	**ft_strings(const char *str, char *charset, char **strings)
{
	int		index;
	int		save;
	int		i;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (ft_strrchr(charset, str[i]) && str[i])
			i++;
		save = i;
		while (ft_strrchr(charset, str[i]) == NULL && str[i])
			i++;
		if (i != save)
		{
			strings[index] = ft_substr(str, save, i - save);
			if (!strings[index++])
				return (free_all_strings(&strings), NULL);
		}
	}
	strings[index] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char *charset)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * (ft_count(s, charset) + 1));
	if (!strings)
		return (NULL);
	strings = ft_strings(s, charset, strings);
	return (strings);
}
