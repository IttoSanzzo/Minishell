/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getarg.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:53:12 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/08 03:03:25 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getarg(char **tab, char const *name)
{
	int	slen;
	int	i;

	if (!tab || !name)
		return (NULL);
	i = -1;
	slen = ft_strlen(name);
	while (tab[++i])
		if (!ft_strncmp(tab[i], name, slen))
			return ((char *)&tab[i][slen]);
	return (NULL);
}
