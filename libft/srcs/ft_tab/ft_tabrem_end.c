/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrem_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:45:45 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:45:46 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabrem_end(char ***old)
{
	int		i;
	int		end;
	char	**new;

	if (!*old)
		return (NULL);
	if (!**old)
		return (*old);
	end = ft_tablen(*old);
	new = (char **)ft_calloc(end, sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < end - 1)
		new[i] = (char *)(old[0][i]);
	free(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
