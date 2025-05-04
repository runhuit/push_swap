/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:44:31 by rabouzer          #+#    #+#             */
/*   Updated: 2025/01/31 06:20:52 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i + 1] && format[i] == '%')
		{
			count += print_args(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int	print_args(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		count += print_ptr(va_arg(*args, void *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count += ft_putnbr(va_arg(*args, unsigned int));
	else if (c == 'x')
		count += ft_putnbr_base(va_arg(*args, unsigned int), MIN, 0);
	else if (c == 'X')
		count += ft_putnbr_base(va_arg(*args, unsigned int), MAJ, 0);
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar('%') + ft_putchar(c);
	return (count);
}
