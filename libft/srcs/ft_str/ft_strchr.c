/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:41:05 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 20:41:51 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	s_ptr = (char *) s;
	while (*s_ptr && *s_ptr != (char)c)
		s_ptr++;
	if (*s_ptr == (char)c)
		return (s_ptr);
	return (NULL);
}
