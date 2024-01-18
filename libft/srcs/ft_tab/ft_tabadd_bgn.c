/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_tabadd_bgn.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/06 20:02:42 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabadd_bgn(char ***old, char *add)
{
	int		i;
	char	**new;

	if (!*old || !add)
		return (NULL);
	new = (char **)ft_calloc(ft_tablen(*old) + 2, sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	new[i] = (char *)(add);
	while (old[0][++i - 1])
		new[i] = (char *)(old[0][i - 1]);
	free(*old);
	*old = new;
	return (new);
}
