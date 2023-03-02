/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/09 17:52:11 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf_fd(int fdd, const char *s, ...);
int		ft_putchar_fdd(char c, int fdd);
int		ft_putnbr_fdd(long nb, int fdd);
int		ft_putstr_fdd(char *s, int fdd);
int		ft_putnbr_base_fdd(long int nb, char *tab, int fdd);
int		print_adress_fdd(void *addr, int fdd);
int		ft_putnbr_undec_fdd(unsigned int n, int fdd);
int		ft_print_type_fdd(va_list args, char c, int fdd);
size_t	ft_strlen_fd(const char *str);

#endif
