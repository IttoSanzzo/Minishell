/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstadd_bgn.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:33:52 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 19:05:20 by marcosv2         ###   ########.fr       */
/*									      */
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
