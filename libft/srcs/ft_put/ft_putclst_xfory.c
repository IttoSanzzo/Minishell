/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putclst_xfory.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/30 16:11:01 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/03 05:13:49 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

// Writes all elements of a clist starting from its "x" position, "y" positions.
void	ft_putclst_xfory(t_clist *lst, int x, int y)
{
	while (lst && x--)
		lst = lst->next;
	if (x + 1)
		return ;
	while (lst && y--)
	{
		ft_putchar(lst->val);
		lst = lst->next;
	}
}
