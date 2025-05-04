/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:33:57 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 06:52:33 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_for_3(t_pile *p)
{
	if (p->p_a[2] < p->p_a[0] || p->p_a[2] < p->p_a[1])
	{
		if (p->p_a[0] > p->p_a[1] && p->p_a[0] > p->p_a[2])
			rotate_x('a', p->size_a, p->p_a);
		else
			rev_r('a', p->size_a, p->p_a);
	}
	if (p->p_a[0] > p->p_a[1])
		swap_x('a', p->p_a, p->size_a);
}

void	radix_sort_b(t_pile *p, int size_b, int bit_size, int j)
{
	while (size_b-- && j <= bit_size && !p_sorted(p))
	{
		if (((p->p_b[0] >> j) & 1) == 0)
			rotate_x('b', p->size_b, p->p_b);
		else
			push_a(p);
	}
	if (p_sorted(p))
		while (p->size_b != 0)
			push_a(p);
}

void	sort_radix(t_pile *p)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = p->size_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = p->size_a;
		while (size-- && !p_sorted(p))
		{
			if (((p->p_a[0] >> j) & 1) == 0)
				push_b(p);
			else
				rotate_x('a', p->size_a, p->p_a);
		}
		radix_sort_b(p, p->size_b, bit_size, j + 1);
	}
	while (p->size_b != 0)
		push_a(p);
}

void	sort_for_5(t_pile *p)
{
	if (p->p_a[0] == 0 || p->p_a[1] == 0)
	{
		while (p->p_a[0] != 0)
			rotate_x('a', p->size_a, p->p_a);
	}
	else
	{
		while (p->p_a[0] != 0)
			rev_r('a', p->size_a, p->p_a);
	}
	push_b(p);
	if (p->p_a[0] == 1 || p->p_a[1] == 1)
	{
		while (p->p_a[0] != 1)
			rotate_x('a', p->size_a, p->p_a);
	}
	else
	{
		while (p->p_a[0] != 1)
			rev_r('a', p->size_a, p->p_a);
	}
	push_b(p);
	sort_for_3(p);
	while (p->size_b != 0)
		push_a(p);
}
