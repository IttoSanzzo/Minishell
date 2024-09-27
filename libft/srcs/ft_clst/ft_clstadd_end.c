/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:14:19 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:14:20 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_end(t_clist **lst, t_clist *new)
{
	t_clist	*last;

	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	else if (new)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (*lst);
}
