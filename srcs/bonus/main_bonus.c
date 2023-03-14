/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:34:33 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/08 11:05:41 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	ft_check_cmd(char *cmd)
{
	if (!ft_strncmp("./", cmd, 2))
		return (write(STDERR_FILENO, "pipex: ./: is a directory\n", 27), 1);
	if (!ft_strncmp(".", cmd, 1))
		return (write(STDERR_FILENO, "pipex: .: filename argument required\n \
		.: usage: . filename [arguments]\n", 71), 1);
	return (0);
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

/*A function to free an 3D array*/
void	ft_free_stack(char ***stack)
{
	int	i;
	int	j;

	i = -1;
	while (stack[++i])
	{
		j = -1;
		while (stack[i][++j])
			free(stack[i][j]);
		free(stack[i]);
	}
	free(stack);
}

/*A function to free struct*/
void	ft_free_all(t_pipex *args)
{
	ft_free_stack(args->cmds);
	close(args->fdd);
	close(args->outfile);
	free(args);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*args;

	if (argc < 5)
		return (ft_printf_fd(1, "Usage:\n{infile} [commands](2...n) {outfile}\
		\nor\nheredoc {limiter} [command] {outfile}"));
	args = ft_init_struct(argc, argv, envp);
	if (!args)
		return (1);
	ft_pipe(args);
	ft_free_all(args);
	return (0);
}
