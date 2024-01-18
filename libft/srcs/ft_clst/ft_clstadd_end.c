/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstadd_end.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:32:54 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 00:52:44 by marcosv2         ###   ########.fr       */
/*									      */
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
