/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/17 16:41:44 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/11/28 16:50:00 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		p_len;
	int		i;
	va_list	args;

	p_len = 0;
	if (!(str[0]))
		return (p_len);
	va_start(args, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			p_len += ft_ftypes(args, str[++i]);
		else
			p_len += ft_printchar(str[i]);
	}
	va_end(args);
	return (p_len);
}
