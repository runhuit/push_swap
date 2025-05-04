/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:18:54 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 07:58:07 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	stock;
	int	i;
	int	nega;

	stock = 0;
	i = 0;
	nega = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nega = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		stock = (stock * 10) + (str[i] - '0');
		i++;
	}
	return (nega * stock);
}
