/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:04 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/03/07 12:12:58 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include"../libft/headers/ft_printf_fd.h"
# include"../libft/headers/libft.h"
# include"../libft/headers/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char	***cmds;
	int		outfile;
	int		fdd;
	char	**envp;
	int		i;
}	t_pipex;

char		*ft_get_path(t_pipex *arg, char *cmd);
char		*get_all_path(char **env);
t_pipex		*ft_init_struct(int argc, char **argv, char **envp);
void		ft_free_tab(char **tab);
int			ft_pipe(t_pipex *args);
void		ft_free_all(t_pipex *args);
void		ft_free_stack(char ***stack);
int			ft_perror(char *error);
char		*ft_rm_quotes(char *cmd);
int			ft_check_quotes(char *cmd, char type_quote);
char		**ft_split_cmd(char	*cmd);
void		ft_cmd_not_found(char *cmd);
int			ft_check_cmd(char *cmd);

#endif
