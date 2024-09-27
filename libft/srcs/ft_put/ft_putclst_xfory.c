/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putclst_xfory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:30:36 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:30:37 by marcosv2         ###   ########.fr       */
/*                                                                            */
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
