/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:23:11 by rabouzer          #+#    #+#             */
/*   Updated: 2024/11/12 07:43:33 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	unit;
	int		min;

	min = -2147483648;
	if (n < 0)
	{
		write (fd, "-", 1);
		n *= -1;
	}
	if (n == min)
	{
		write (fd, "2", 1);
		n = 147483648;
	}
	unit = (n % 10);
	unit = unit + '0';
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	write (fd, &unit, 1);
	return ;
}
