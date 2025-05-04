/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:52:01 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:52:36 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*d;
	size_t			calc;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	calc = size * nmemb;
	if (calc / size != nmemb)
		return (NULL);
	d = malloc((size * nmemb) * sizeof(char));
	if (!d)
		return (NULL);
	ft_bzero((void *)d, size * nmemb);
	return ((void *)d);
}
