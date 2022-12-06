/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:23 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/24 13:20:42 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(long int n);
int		ft_putstr(char *s);
int		ft_putnbr_base(long int nb, char *tab);
int		print_adress(void *addr);
int		ft_putnbr_undec(unsigned int n);
int		ft_print_type(va_list args, char c);

#endif
