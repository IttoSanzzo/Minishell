/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstpos.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 00:54:17 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 01:51:52 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstpos(t_clist *lst, int pos)
{
	t_clist	*temp;

	if (!lst || pos < 0)
		return (NULL);
	temp = lst;
	while (pos-- && temp)
		temp = temp->next;
	if (pos + 1)
		return (NULL);
	return (temp);
}
