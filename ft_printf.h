/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:31:54 by yrio              #+#    #+#             */
/*   Updated: 2023/11/30 11:31:58 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdio.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char const *s);
int		ft_putnbr(int n);
int		ft_putunsignednbr(unsigned int n);
int		ft_print_ptr(void *ptr, char c);
int		ft_print_hexa(void *ptr, char c);
int		ft_printf(const char *format, ...);

#endif