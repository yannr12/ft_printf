/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:52:02 by yrio              #+#    #+#             */
/*   Updated: 2023/11/30 11:25:47 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_hexa_int(unsigned int nbr, char c)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hexa_int(nbr / 16, c);
	if (c == 'X')
		count += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

int	putnbr_hexa_long(unsigned long nbr, char c)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += putnbr_hexa_long(nbr / 16, c);
	if (c == 'X')
		count += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		count += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (count);
}

int	ft_print_ptr(void *ptr, char c)
{
	unsigned long	nbr;
	int				count;

	count = 0;
	nbr = (unsigned long)ptr;
	if (nbr == 0 && c == 'p')
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += putnbr_hexa_long(nbr, c);
	}
	return (count);
}

int	ft_print_hexa(void *ptr, char c)
{
	unsigned long	nbr;
	int				count;

	nbr = (unsigned long)ptr;
	count = 0;
	count += putnbr_hexa_int((unsigned int)nbr, c);
	return (count);
}
