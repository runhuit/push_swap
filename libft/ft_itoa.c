/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:18:32 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:43:27 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_num(int n)
{
	long int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	int			i;
	char		*str;
	long int	nb;

	nb = n;
	len = ft_strlen_num(n);
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	str[len + 1] = 0;
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		i++;
	}
	while (len >= i)
	{
		str[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (str);
}
