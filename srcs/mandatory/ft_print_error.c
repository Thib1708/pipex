/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:36:21 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/07 11:42:37 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void ft_cmd_not_found(char *cmd)
{ 
	char *tmp;

	tmp = ft_join_mlt(3, "pipex: ", cmd, ": command not found\n");
	write(STDERR_FILENO, tmp, ft_strlen(tmp));
	free(tmp);
}