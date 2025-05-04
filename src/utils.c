/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:35:04 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 06:52:11 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	free_all(t_pile *p)
{
	if (p->p_a != NULL)
		free (p->p_a);
	if (p->p_b != NULL)
		free (p->p_b);
	if (p != NULL)
		free (p);
	return (0);
}

int	p_sorted(t_pile *p)
{
	int	i;

	i = 0;
	while (i < p->size_a - 1)
	{
		if (p->p_a[i] > p->p_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
