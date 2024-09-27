/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:14:07 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:14:10 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clstlen(t_clist *lst)
{
	t_clist	*last;
	int		i;

	last = lst;
	i = 0;
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}
