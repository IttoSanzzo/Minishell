/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:43:52 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/28 21:49:57 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	i;
	size_t	total;

	if (size == 0)
		return (ft_strlen(src));
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	d = ft_strlen(dst);
	total = d + ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && d < (size - 1))
	{
		dst[d] = src[i];
		d++;
		i++;
	}
	dst[d] = '\0';
	return (total);
}
