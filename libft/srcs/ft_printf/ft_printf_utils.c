/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:28:46 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:28:48 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lputchar(int c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

int	ft_nbrlen(int nb)
{
	if (!(nb / 10))
		return (1 + 1 * (nb < 0));
	return (1 + ft_nbrlen(nb / 10));
}
