/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:21:54 by rabouzer          #+#    #+#             */
/*   Updated: 2025/01/31 06:16:02 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define MAJ	0
# define MIN	1

int	ft_putchar(char c);
int	print_ptr(void *ptr);
int	ft_printf(const char *format, ...);
int	ft_putstr(char	*str);
int	ft_putnbr_base(unsigned int nb, int type, int i);
int	ft_putnbr(long int nb);
int	ft_putnbr_base_p(unsigned long long int nb, int type, int i);
int	print_args(char c, va_list *args);

#endif