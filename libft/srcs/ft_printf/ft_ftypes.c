/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftypes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:28:05 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:28:07 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ftypes(va_list args, const char format)
{
	int	f_len;

	f_len = 0;
	if (format == '%')
		f_len += ft_printpercent();
	else if (format == 'c')
		f_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		f_len += ft_printstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		f_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		f_len += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		f_len += ft_printhex(va_arg(args, int), format);
	else if (format == 'p')
		f_len += ft_printpointer(va_arg(args, unsigned long long));
	return (f_len);
}
