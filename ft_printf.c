/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:40:58 by yrio              #+#    #+#             */
/*   Updated: 2024/01/30 15:57:00 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_output(const char *format, va_list args, int count)
{
	char	*test_str;

	if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 's')
	{
		test_str = va_arg(args, char *);
		if (test_str == NULL)
			count = write(1, "(null)", 6);
		else
			count = ft_putstr(test_str);
	}
	else if (*format == 'p')
		count = ft_print_ptr(va_arg(args, void *), 'p');
	else if (*format == 'd' || *format == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count = ft_putunsignednbr(va_arg(args, unsigned int));
	else if (*format == 'x')
		count = ft_print_hexa(va_arg(args, void *), 'x');
	else if (*format == 'X')
		count = ft_print_hexa(va_arg(args, void *), 'X');
	else if (*format == '%')
		count = ft_putchar(*format);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			count += ft_output(format, args, count);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/*
// test conversion adresse en hexadecimale (void *) %p
int main(void) 
{
	char	*str = "blabla";
	int rtn_printf = printf("%p\n", &str);
	int rtn_ft_printf = ft_printf("%p\n", &str);
	// test nombre de caractere affiche
	printf("ft_printf --> %d\nprintf --> %d\n", rtn_ft_printf, rtn_printf);
    return 0;
}
*/

//%x et %X c'est comme p sans x0 devant
//%u c'est un unsigned donc ca gere pas les negatifs

/*
int	main(void)
{
	//char	*str = NULL;
	//char	*str2 = NULL;
	int value = ft_printf(" %x %x ", 0, "j");
	int	value2 = printf(" %x %x ", 0, "j");
	printf("Nb ft_printf -> %d\nNb printf -> %d", value, value2);
	return (0);
*/


/*
int	main(void)
{
	//char	*str = NULL;
	//char	*str2 = NULL;
	int	value = ft_printf("as% ");
	int	value2 = printf("as% ");
	printf("Nb ft_printf -> %d\nNb printf -> %d", value, value2);
	return (0);
}
*/
