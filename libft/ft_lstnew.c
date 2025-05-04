/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzer <rabouzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:24:40 by rabouzer          #+#    #+#             */
/*   Updated: 2024/10/29 05:24:51 by rabouzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newcontent;

	newcontent = malloc(sizeof(t_list));
	if (!newcontent)
		return (NULL);
	newcontent->content = content;
	newcontent->next = NULL;
	return (newcontent);
}
