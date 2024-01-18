/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstfree.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:34:24 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 02:26:30 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_freeclst(t_clist **lst)
{
	t_clist	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
	return (NULL);
}
