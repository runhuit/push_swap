/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 06:50:49 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:41:56 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	n = (size_t)ft_strlen(s);
	if (start >= n)
		re = ft_calloc(1, sizeof(char));
	else if ((n - start) < len)
		re = ft_calloc(((n - start) + 1), sizeof(char));
	else
		re = malloc((len + 1) * sizeof(char));
	if (!re)
		return (NULL);
	i = 0;
	if (start >= n)
		return ((char *)re);
	while (i < len && s[start + i] != '\0')
	{
		re[i] = (unsigned char)s[start + i];
		i++;
	}
	re[i] = 0;
	return ((char *)re);
}
