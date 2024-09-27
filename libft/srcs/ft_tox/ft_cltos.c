/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cltos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:47:42 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:47:49 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cltos(t_clist *lst)
{
	t_clist	*temp;
	char	*str;
	char	*ret;

	if (!lst)
		return (NULL);
	str = (char *)ft_calloc(ft_clstlen(lst) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	temp = lst;
	while (temp)
	{
		*str++ = temp->val;
		temp = temp->next;
	}
	return (ret);
}
