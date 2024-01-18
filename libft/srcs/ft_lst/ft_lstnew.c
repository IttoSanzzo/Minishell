/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:37:34 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 15:23:22 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *val)
{
	t_list	*newlst;

	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return (NULL);
	newlst->val = val;
	newlst->next = NULL;
	return (newlst);
}
