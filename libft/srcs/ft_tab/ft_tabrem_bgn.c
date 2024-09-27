/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrem_bgn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:45:50 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:45:51 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_bgn(char ***old)
{
	int		i;
	char	**new;

	if (!*old)
		return (NULL);
	if (!**old)
		return (*old);
	new = (char **)ft_calloc(ft_tablen(*old), sizeof(char *));
	if (!new)
		return (NULL);
	i = 0;
	free(**old);
	while (old[0][++i])
		new[i - 1] = (char *)(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
