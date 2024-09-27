/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnclst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:29:56 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:29:57 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes all values of a clist in the stdout, till it's end.
void	ft_putnclst(t_clist *lst, int n)
{
	while (lst && n--)
	{
		ft_putchar(lst->val);
		lst = lst->next;
	}
}
