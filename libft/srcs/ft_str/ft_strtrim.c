/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:47:21 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 20:51:07 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	sup;

	if (!s1 || !set)
		return (0);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	sup = ft_strlen(s1);
	while (sup && ft_strchr(set, s1[sup]))
		sup--;
	return (ft_substr(s1, 0, sup + 1));
}
