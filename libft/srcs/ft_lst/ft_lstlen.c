/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:24:58 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:24:59 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *lst)
{
	t_list	*last_check;
	int		i;

	last_check = lst;
	i = 0;
	while (last_check)
	{
		last_check = last_check->next;
		i++;
	}
	return (i);
}
