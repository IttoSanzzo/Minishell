/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:25:44 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:25:46 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_end(t_list **lst, t_list *new)
{
	t_list	*last_el;

	if (lst && *lst)
	{
		last_el = *lst;
		while (last_el->next)
			last_el = last_el->next;
		last_el->next = new;
	}
	else
		if (lst)
			*lst = new;
}
