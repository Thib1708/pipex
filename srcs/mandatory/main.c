/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/21 16:29:17 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*A function to print error message on the error output*/
int	ft_perror(char *error)
{
	char	*join;

	join = ft_strjoin("pipex: ", error);
	perror(join);
	free(join);
	return (1);
}

/*A function to free an 2D array*/
void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*A function to free struct*/
void	ft_free_arg(t_arg *arg)
{
	ft_free_tab(arg->cmd1);
	ft_free_tab(arg->cmd2);
	free(arg);
}

int	main(int argc, char **argv, char **env)
{
	t_arg	*arg;

	if (argc != 5)
	{
		ft_printf("Usage: {infile} [command1] [command2] {outfile}.");
		return (1);
	}
	if (!env[0])
		return (0);
	arg = init_arg(argv, env);
	if (!arg)
		return (1);
	if (ft_pipe(arg))
		return (ft_free_arg(arg), 1);
	ft_free_arg(arg);
	return (0);
}
