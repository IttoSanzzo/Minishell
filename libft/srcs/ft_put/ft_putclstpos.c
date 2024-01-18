/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putclstpos.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/30 16:11:01 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/03 05:04:16 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

// Writes all elements of a clist starting from its "pos" position.
void	ft_putclstpos(t_clist *lst, int pos)
{
	while (lst && pos--)
		lst = lst->next;
	if (pos + 1)
		return ;
	ft_putclst(lst);
}
