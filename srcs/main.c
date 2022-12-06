/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:27:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/05 17:45:31 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/pipex.h"

int main(int argc, char **argv)
{
	int fd[2];
	int id1;
	
	(void)argc;
	(void)argv;
	// if (argc != 4)
	// 	exit(1);
	if (pipe(fd) == -1)
		return(1);
	id1 = fork();
	if (id1 < 0)
		return (2);
	if (id1 == 0)
	{
		execve(argv[2], NULL, NULL);
		// execlp(argv[3], argv[3], NULL);
	}
	waitpid(id1, NULL, 0);
}