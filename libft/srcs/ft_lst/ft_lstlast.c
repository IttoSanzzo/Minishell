/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:36:44 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 19:36:48 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	if (!lst)
		return (0);
	return (lst);
}
