/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd_bgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:13 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:13:14 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_bgn(t_clist **lst, t_clist *new)
{
	if (!*lst)
	{
		*lst = new;
		return (*lst);
	}
	if (new)
	{
		new->next = *lst;
		*lst = new;
		return (*lst);
	}
	return (NULL);
}
