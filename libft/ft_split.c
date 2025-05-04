/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:18:13 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 06:54:11 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static void	ft_free(char **re, int y)
{
	int	i;

	i = 0;
	while (i < y)
		free (re[i++]);
	free (re);
}

static char	*ft_dup_str(char const *s, int i, char **re, int y)
{
	char	*temp;
	int		j;

	j = 0;
	temp = malloc ((1 + i) * sizeof(char));
	if (!temp)
	{
		ft_free(re, j);
		return (NULL);
	}
	if (!temp)
		return (NULL);
	while (j < i)
	{
		temp[j] = s[j];
		j++;
	}
	temp[j] = 0;
	re[y] = temp;
	return (temp);
}

static int	ft_resize(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c && s[0] != '\0')
		j += 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	re = malloc(sizeof(char *) * (ft_resize(s, c) + 1));
	if (!re)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	while (*s)
	{
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!ft_dup_str(s, i, re, j++))
			return (NULL);
		s += i;
		while (*s == c && *s != '\0')
			s++;
	}
	re[j] = NULL;
	return (re);
}
