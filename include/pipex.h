/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:04 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/10 17:38:25 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include"../libft/headers/ft_printf.h"
# include"../libft/headers/libft.h"
# include"unistd.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_arg
{
	char	*file1;
	char	**cmd1;
	char	*file2;
	char	**cmd2;
	char	**env;
}	t_arg;

t_arg	*init_arg(char **argv, char **env);
char	*ft_get_path(t_arg *args, char *cmd);
char	*get_all_path(char **env);
void		ft_child(t_arg *arg, int *fds);
void		ft_parent(t_arg *arg, int *fds);
void	ft_free_tab(char **tab);
int		ft_pipe(t_arg *arg);

#endif