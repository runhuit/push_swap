/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 06:52:22 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:53:14 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sm;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	sm = malloc(sizeof(char) * (i + j + 1));
	if (!sm)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		sm[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		sm[i + j] = s2[j];
		j++;
	}
	sm[i + j] = 0;
	return (sm);
}
