/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strtrim_xtoy.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/16 16:34:09 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 03:11:55 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_xtoy(char *s, int x, int y)
{
	int		i;
	char	*trim;

	if (!s || x < 0 || y < 0 || x > y || (int)ft_strlen(s) - 1 < x)
		return (NULL);
	trim = (char *)ft_calloc((y - x) + 2, sizeof(char));
	if (!trim)
		return (NULL);
	i = -1;
	while (((x + ++i) <= y) && (s[x + i]))
		trim[i] = s[x + i];
	return (trim);
}
