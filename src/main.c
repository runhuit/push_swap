/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:34:22 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 19:30:55 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*p;

	if (ac < 2)
		return (0);
	p = malloc(sizeof * p);
	if (!check_and_init(ac, av, p))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	put_index(p);
	if (!p_sorted(p))
	{
		if (p->size_a == 2)
			swap_x('a', p->p_a, p->size_a);
		else if (p->size_a == 3)
			sort_for_3(p);
		else if (p->size_a == 5)
			sort_for_5(p);
		else
			sort_radix(p);
	}
	free_all(p);
}

int	check_and_init(int ac, char **av, t_pile *p)
{
	if (!check_num(ac, av))
	{
		free (p);
		return (0);
	}
	if (!init_pile(ac, av, p))
		return (free_all(p));
	if (!put_pile(ac, av, p))
		return (0);
	if (!last_checks(p))
		return (free_all(p));
	return (1);
}

void	put_index(t_pile *p)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * p->size_a + 1);
	while (i < p->size_a)
	{
		j = 0;
		temp[i] = 0;
		while (j < p->size_a)
		{
			if (p->p_a[i] > p->p_a[j])
				temp[i] += 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < p->size_a)
	{
		p->p_a[i] = temp[i];
		i++;
	}
	free (temp);
}
