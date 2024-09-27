/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstpos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:48 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:13:51 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstpos(t_clist *lst, int pos)
{
	t_clist	*temp;

	if (!lst || pos < 0)
		return (NULL);
	temp = lst;
	while (pos-- && temp)
		temp = temp->next;
	if (pos + 1)
		return (NULL);
	return (temp);
}
