/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:28:11 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:28:12 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned int nb)
{
	int		len;
	char	nbr;

	if (nb > 9)
		len = ft_printnbr(nb / 10);
	nbr = nb % 10 + 48;
	write(1, &nbr, 1);
	if (!(nb / 10))
		return (1);
	return (1 + len);
}
