/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:04 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/09 16:12:28 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include"../libft/headers/ft_printf.h"
# include"../libft/headers/libft.h"
# include "unistd.h"
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_arg
{
	char	*infile;
	char	**cmd1;
	char	*outfile;
	char	**cmd2;
	char	**env;
}	t_arg;

t_arg	*init_arg(char **argv, char **env);
char	*ft_get_path(t_arg *args, char *cmd);
char	*get_all_path(char **env);
int		ft_child(t_arg *arg, int *fds);
int		ft_parent(t_arg *arg, int *fds);
void	ft_free_tab(char **tab);
int		ft_pipe(t_arg *arg);
int		ft_check_quotes(char *cmd, char type_quote);
char	*ft_rm_quotes(char *cmd);
int		ft_perror(char *error);
char	**ft_split_cmd(char	*cmd);

#endif
