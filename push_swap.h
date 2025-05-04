/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 06:35:35 by rabouzer          #+#    #+#             */
/*   Updated: 2025/05/03 19:15:57 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_pile
{
	int	size_a;
	int	size_b;
	int	*p_a;
	int	*p_b;
}	t_pile;

int		put_pile(int ac, char **av, t_pile *p);
void	push_b(t_pile *p);
void	push_a(t_pile *p);
void	swap_x(char x, int *p_x, int size_x);
void	rotate_x(char x, int size_x, int *p_x);
void	rev_r(char x, int size_x, int *p_x);
void	sort_for_3(t_pile *p);
void	sort_radix(t_pile *p);
void	radix_sort_b(t_pile *p, int size_b, int bit_size, int j);
void	put_index(t_pile *p);
int		check_num(int ac, char **av);
int		check_and_init(int ac, char **av, t_pile *p);
int		init_pile(int ac, char **av, t_pile *p);
int		last_checks(t_pile *p);
int		free_all(t_pile *p);
int		p_sorted(t_pile *p);
int		put_pile_bis(char *a, int j, int index, t_pile *p);
int		check_inter(char *str);
int		check_only(char *av, int j);
int		if_neg(int j, long int *temp, char *a, t_pile *p);
void	sort_for_5(t_pile *p);
int		if_neg_bis(int j, long int *temp, char *a);

#endif
