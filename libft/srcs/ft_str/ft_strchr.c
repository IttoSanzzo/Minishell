/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:34:52 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:34:53 by marcosv2         ###   ########.fr       */
/*                                                                            */
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
