/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:34:51 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 06:52:23 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_pile *p)
{
	int	i;

	if (p->size_a == 0)
		return ;
	if (p->size_b == 0)
		p->p_b[0] = p->p_a[0];
	else
	{
		i = p->size_b;
		while (i >= 0)
		{
			p->p_b[i + 1] = p->p_b[i];
			i--;
		}
		p->p_b[0] = p->p_a[0];
	}
	p->size_b++;
	i = -1;
	while (i++ < p->size_a - 1)
		p->p_a[i] = p->p_a[i + 1];
	p->size_a--;
	ft_printf("pb\n");
}

void	push_a(t_pile *p)
{
	int	i;

	if (p->size_b == 0)
		return ;
	i = p->size_a;
	if (p->size_a == 0)
		p->p_a[0] = p->p_b[0];
	else
	{
		while (i >= 0)
		{
			p->p_a[i + 1] = p->p_a[i];
			i--;
		}
		p->p_a[0] = p->p_b[0];
	}
	p->size_a++;
	i = -1;
	while (i++ < p->size_b)
		p->p_b[i] = p->p_b[i + 1];
	p->size_b--;
	ft_printf("pa\n");
}

void	swap_x(char x, int *p_x, int size_x)
{
	int	tmp;

	if (size_x < 2)
		return ;
	tmp = p_x[0];
	p_x[0] = p_x[1];
	p_x[1] = tmp;
	ft_printf("s%c\n", x);
}

void	rotate_x(char x, int size_x, int *p_x)
{
	int	tmp;
	int	i;

	if (size_x < 2)
		return ;
	i = -1;
	tmp = p_x[0];
	while (i++ < size_x - 1)
		p_x[i] = p_x[i + 1];
	p_x[size_x - 1] = tmp;
	ft_printf("r%c\n", x);
}

void	rev_r(char x, int size_x, int *p_x)
{
	int	tmp;
	int	i;

	if (size_x < 2)
		return ;
	i = size_x;
	tmp = p_x[size_x - 1];
	while (i-- > 1)
		p_x[i] = p_x[i - 1];
	p_x[i] = tmp;
	ft_printf("rr%c\n", x);
}
