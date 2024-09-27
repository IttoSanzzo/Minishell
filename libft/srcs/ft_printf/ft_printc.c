/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:29:01 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:29:02 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printc(char *color, const char *str, ...)
{
	int		p_len;
	int		i;
	va_list	args;

	p_len = 0;
	if (!(str[0]))
		return (p_len);
	va_start(args, str);
	i = -1;
	p_len += ft_printstr(color);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			p_len += ft_ftypes(args, str[++i]);
		else
			p_len += ft_printchar(str[i]);
	}
	va_end(args);
	p_len += ft_printstr(C_WHITE);
	return (p_len);
}
