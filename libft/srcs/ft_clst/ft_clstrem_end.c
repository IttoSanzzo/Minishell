/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstrem_end.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:32:54 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/06 20:25:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_end(t_clist **lst)
{
	t_clist	*last;

	if (!*lst)
		return (NULL);
	last = *lst;
	if (!last->next)
		return (ft_nfreeclst(lst));
	while (last->next->next)
		last = last->next;
	ft_nfreeclst(&last->next);
	return (*lst);
}
