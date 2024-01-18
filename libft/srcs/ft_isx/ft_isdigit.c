/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:14:00 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 20:14:14 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
