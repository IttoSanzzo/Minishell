/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:45:56 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/11 15:09:52 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	count = 0;
	if (n <= 0)
		return (0);
	while (s1[count] && (s1[count] == s2[count]) && count < (n - 1))
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
