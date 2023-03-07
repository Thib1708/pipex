/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:36:21 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/07 12:09:49 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex_bonus.h"

void	ft_cmd_not_found(char *cmd)
{
	char	*tmp;

	tmp = ft_join_mlt(3, "pipex: ", cmd, ": command not found\n");
	write(STDERR_FILENO, tmp, ft_strlen(tmp));
	free(tmp);
}

/*A function to print error message on the error output*/
int	ft_perror(char *error)
{
	char	*join;

	join = ft_strjoin("pipex: ", error);
	perror(join);
	free(join);
	return (1);
}
