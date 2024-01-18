/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/19 15:32:54 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 16:50:33 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned int nb)
{
	if (!(nb / 16))
		return (1);
	return (1 + ft_hexlen(nb / 16));
}

static void	ft_puthex(int nb, char *code, const char format)
{
	write(1, &code[nb + 6 * (format == 'X' && code[nb] >= 'a')], 1);
}

static	void	ft_hexrec(unsigned int nb, const char format)
{
	if (nb > 15)
		ft_hexrec(nb / 16, format);
	ft_puthex(nb % 16, "0123456789abcdefABCDEF", format);
}

int	ft_printhex(int nb, const char format)
{
	ft_hexrec(nb, format);
	return (ft_hexlen(nb));
}
