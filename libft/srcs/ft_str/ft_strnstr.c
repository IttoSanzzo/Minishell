/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:46:23 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/28 21:50:54 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while ((i < len) && (big[i] != '\0'))
	{
		if (big[i] == little[j])
		{
			while (little[j] != '\0' && big[j + i] && (j + i) < len)
			{
				if (big[j + i] == little[j])
					j++;
				else
					break ;
			}
			if (little[j] == '\0')
				return ((char *)big + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
