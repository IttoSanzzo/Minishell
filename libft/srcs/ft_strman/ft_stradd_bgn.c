/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_bgn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:35:35 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:41:37 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd_bgn(char **old, char add)
{
	int		i;
	char	*new;

	if (!*old)
		return (ft_strnew(old, add));
	new = (char *)ft_calloc(ft_strlen(*old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	new[i] = (char)(add);
	while (old[0][++i - 1])
		new[i] = (char)old[0][i - 1];
	free(*old);
	*old = new;
	return (new);
}
