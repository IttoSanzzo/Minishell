/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:34:24 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 00:49:56 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->val);
			free(*lst);
			*lst = temp;
		}
	}
	lst = NULL;
}
