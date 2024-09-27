/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:46:10 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:46:11 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabadd_end(char ***old, char *add)
{
	int		i;
	char	**new;

	if (!*old || !add)
		return (NULL);
	new = (char **)ft_calloc(ft_tablen(*old) + 2, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (old[0][++i])
		new[i] = (char *)(old[0][i]);
	new[i] = (char *)(add);
	free(*old);
	*old = new;
	return (new);
}
