/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/19 15:34:02 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 16:51:17 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptrlen(uintptr_t num)
{
	if (!(num / 16))
		return (1);
	return (1 + ft_ptrlen(num / 16));
}

static void	ft_putptr(uintptr_t num)
{
	char	nbr;

	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			nbr = num + 48;
		else
			nbr = num - 10 + 'a';
		write(1, &nbr, 1);
	}
}

int	ft_printpointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}
