/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:28:33 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:28:37 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb)
{
	int		len;
	char	nbr;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	len = ft_nbrlen(nb);
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_printnbr(nb / 10);
	nbr = nb % 10 + 48;
	write(1, &nbr, 1);
	return (len);
}
