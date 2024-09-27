/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:24:51 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:24:53 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*lastnew_el;

	if (lst && f && del)
	{
		new_list = ft_lstnew(f(lst->val));
		lst = lst->next;
		lastnew_el = new_list;
		while (lst && new_list)
		{
			lastnew_el->next = ft_lstnew(f(lst->val));
			if (!lastnew_el->next)
				ft_lstfree(&new_list, del);
			else
			{
				lastnew_el = lastnew_el->next;
				lst = lst->next;
			}
		}
		return (new_list);
	}
	return (0);
}
