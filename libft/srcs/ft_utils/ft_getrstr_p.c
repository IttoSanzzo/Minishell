/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getrstr_p.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/25 14:40:36 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 22:40:51 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_getrstr_p(char **tab, char const *name)
{
	int		nlen;
	int		i;

	if (!tab || !name)
		return (-1);
	nlen = ft_strlen(name) + 1;
	i = ft_tablen(tab);
	while (--i >= 0)
		if (!ft_strncmp(tab[i], name, nlen))
			return (i);
	return (-1);
}
