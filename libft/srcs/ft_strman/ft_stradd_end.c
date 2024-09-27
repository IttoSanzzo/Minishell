/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:41:27 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:41:28 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_end(char **old, char add)
{
	int		i;
	char	*new;

	if (!*old)
		return (ft_strnew(old, add));
	new = (char *)ft_calloc(ft_strlen(*old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[0][++i])
		new[i] = (char)(old[0][i]);
	new[i] = (char)(add);
	free(*old);
	*old = new;
	return (new);
}
