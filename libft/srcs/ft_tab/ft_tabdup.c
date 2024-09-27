/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:46:00 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:46:01 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **old)
{
	int		i;
	char	**new;

	if (!old)
		return (NULL);
	new = (char **)ft_calloc(ft_tablen(old) + 1, sizeof(char *));
	i = -1;
	while (old[++i])
		new[i] = ft_strdup(old[i]);
	return (new);
}
