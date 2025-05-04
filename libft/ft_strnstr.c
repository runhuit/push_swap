/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:12:29 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:45:34 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!ft_strlen(little))
		return ((char *) big);
	if (!big && len <= 0)
		return (NULL);
	while (big[i] && len >= ft_strlen(little) && len != 0)
	{
		j = 0;
		while (big[i] == little[j] && big[i] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char *)big + (i - j));
		else
			i -= j;
		i++;
	}
	return (NULL);
}
