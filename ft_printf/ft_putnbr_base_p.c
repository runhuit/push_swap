/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 03:55:39 by rabouzer          #+#    #+#             */
/*   Updated: 2024/11/14 07:01:56 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, int type, int i)
{
	char		unit;
	char		*base;

	if (type == MIN)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	unit = (nb % 16);
	unit = base[(unsigned int)unit];
	if (nb > 15)
		i = ft_putnbr_base(nb / 16, type, i);
	write (1, &unit, 1);
	i++;
	return (i);
}

int	ft_putnbr_base_p(unsigned long long int nb, int type, int i)
{
	char	unit;
	char	*base;

	if (type == MIN)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb > 15)
		i = ft_putnbr_base_p(nb / 16, type, i);
	unit = base[(unsigned long long int)(nb % 16)];
	write(1, &unit, 1);
	i++;
	return (i);
}

int	print_ptr(void *ptr)
{
	int	i;

	if (!ptr)
	{
		ft_putstr("(nil)");
		i = 5;
		return (i);
	}
	i = 2;
	write(1, "0x", 2);
	i = ft_putnbr_base_p((unsigned long long int)ptr, MIN, i);
	return (i);
}
