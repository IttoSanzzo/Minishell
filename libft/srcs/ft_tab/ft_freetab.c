/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 20:48:55 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 05:23:16 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freetab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return (NULL);
	while (tab[++i])
		ft_free(tab[i]);
	if (tab)
		ft_free(tab);
	return (NULL);
}
