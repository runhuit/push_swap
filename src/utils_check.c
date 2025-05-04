/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:34:56 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 19:15:46 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_only(char *av, int j)
{
	if ((((!(ft_isdigit(av[j])) && (av[j] != ' '))
				&& av[j] != '-') && av[j] != '+' && av[j] != ' ')
		|| (av[j] == '-' && av[j + 1] == '\0')
		|| (av[j] == '+' && av[j + 1] == '\0')
		|| (av[j] == '-' && av[j + 1] == ' ')
		|| (av[j] == '+' && av[j + 1] == ' ')
		|| (av[j] == '-' && av[j + 1] == '+')
		|| (av[j] == '-' && av[j + 1] == '-')
		|| (av[j] == '+' && av[j + 1] == '+')
		|| (av[j] == '+' && av[j + 1] == '-'))
		return (0);
	else if (ft_isdigit(av[j]))
		return (2);
	return (1);
}

int	check_inter(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i] != 0)
	{
		if (!(ft_isdigit(str[i])) && (str[i] != ' ')
			&& str[i - 1] != ' ' && i != 0)
			return (0);
		i++;
	}
	return (1);
}

int	if_neg(int j, long int *temp, char *a, t_pile *p)
{
	int	i;

	i = 0;
	if (*temp < 0)
		j = if_neg_bis(j, temp, a);
	else
	{
		*temp = *temp * (a[j++] - 48);
		while (a[j] != ' ' && a[j] != '\0')
		{
			*temp = (*temp * 10) + (a[j++] - 48);
			if (*temp > 2147483647)
				i = 1;
		}
	}
	if (i != 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_all(p);
		exit (0);
	}
	return (j);
}

int	if_neg_bis(int j, long int *temp, char *a)
{
	*temp = *temp * (a[j++] - 48);
	while (a[j] != ' ' && a[j] != '\0')
	{
		if (*temp > 0)
			*temp *= -1;
		*temp = (*temp * 10) - (a[j++] - 48);
	}
	return (j);
}
