/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_ansi_go.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 06:19:59 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/09 22:45:20 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_ansi_go(int x, int y)
{
	ft_putstr("\033[");
	ft_putnbr(y);
	ft_putchar(';');
	ft_putnbr(x);
	ft_putchar('H');
}
