/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getstr_p.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/25 14:40:36 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 22:43:05 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_getstr_p(char **tab, char const *name)
{
	int		nlen;
	int		i;

	if (!tab || !name)
		return (-1);
	nlen = ft_strlen(name) + 1;
	i = -1;
	while (tab[++i])
		if (!ft_strncmp(tab[i], name, nlen))
			return (i);
	return (-1);
}
