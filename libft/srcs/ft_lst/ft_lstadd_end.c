/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:32:54 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 15:11:25 by marcosv2         ###   ########.fr       */
/*									      */
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
