/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:33:26 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 19:15:17 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	last_checks(t_pile *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->size_a > i)
	{
		j = i + 1;
		while (p->size_a > j)
		{
			if (p->p_a[j] == p->p_a[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	put_pile(int ac, char **av, t_pile *p)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < ac)
	{
		index = put_pile_bis(av[i], 0, index, p);
		if (index == -1)
		{
			free_all(p);
			return (0);
		}
		i++;
	}
	return (1);
}

int	put_pile_bis(char *a, int j, int index, t_pile *p)
{
	long int	temp;

	while (a[j] != '\0')
	{
		temp = 1;
		if (a[j] != ' ')
		{
			if (a[j] == '+' || a[j] == '-')
			{
				if (a[j] == '-')
					temp *= -1;
				j++;
			}
			j = if_neg(j, &temp, a, p);
			if (temp > 2147483647 || temp < -2147483648)
				return (-1);
			p->p_a[index++] = temp;
			if (a[j] == '\0')
				break ;
		}
		j++;
	}
	return (index);
}

int	init_pile(int ac, char **av, t_pile *p)
{
	int	i;
	int	j;

	i = 1;
	p->size_a = 0;
	p->size_b = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((ft_isdigit(av[i][j]) && av[i][j + 1] == ' ')
				|| (ft_isdigit(av[i][j]) && av[i][j + 1] == '\0'))
				p->size_a++;
			j++;
		}
		i++;
	}
	p->p_a = ft_calloc(p->size_a + 1, sizeof(int));
	if (p->p_a == NULL)
		return (0);
	p->p_b = ft_calloc(p->size_a + 1, sizeof(int));
	if (p->p_b == NULL)
		return (0);
	return (1);
}

int	check_num(int ac, char **av)
{
	int	i;
	int	j;
	int	t;

	i = 1;
	while (i < ac)
	{
		j = 0;
		t = 0;
		while (av[i][j] != '\0')
		{
			if (!check_only(av[i], j))
				return (0);
			else if (check_only(av[i], j) == 1)
				t++;
			j++;
		}
		if (t == j)
			return (0);
		if (!check_inter(av[i]))
			return (0);
		i++;
	}
	return (1);
}
