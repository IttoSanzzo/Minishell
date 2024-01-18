/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstrem_bgn.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:33:52 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 21:02:45 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_bgn(t_clist **lst)
{
	t_clist	*temp;

	if (!*lst)
		return (NULL);
	temp = *lst;
	*lst = temp->next;
	free(temp);
	return (*lst);
}
