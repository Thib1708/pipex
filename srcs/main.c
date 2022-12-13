/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/13 11:58:53 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	while (*tab)
	{
		free(*tab);
		tab++;
	}
}

void	ft_free_arg(t_arg *arg)
{
	ft_free_tab(arg->cmd1);
	free(arg->cmd1);
	ft_free_tab(arg->cmd2);
	free(arg->cmd2);
	free(arg);
}

int	main(int argc, char **argv, char **env)
{
	t_arg	*arg;

	if (argc != 5)
		return (1);
	arg = init_arg(argv, env);
	if (!arg)
		return (1);
	if (ft_pipe(arg) == 1)
		return (1);
	ft_free_arg(arg);
	return (0);
}

