/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 05:59:47 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:43:12 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s1;
	int				i;

	i = 0;
	s1 = (unsigned char *) s;
	while (s1[i])
	{
		if (s1[i] == ((unsigned char) c))
			return ((char *) &s1[i]);
		i++;
	}
	if ((char) c == 0)
		return ((char *) &s1[i]);
	return (NULL);
}
