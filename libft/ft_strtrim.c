/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:16:27 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:39:43 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*sm;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	start = 0;
	end = (ft_strlen(s1)) - 1;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	i = 0;
	sm = malloc(sizeof(char) * (end - start) + 2);
	if (!sm)
		return (NULL);
	while (start <= end)
		sm[i++] = s1[start++];
	sm[i] = 0;
	return (sm);
}
