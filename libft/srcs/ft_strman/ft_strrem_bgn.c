/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem_bgn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:42:09 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:42:09 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrem_bgn(char **old)
{
	int		i;
	char	*new;

	if (!*old)
		return (NULL);
	if (!old[0][0])
		return (*old);
	new = (char *)ft_calloc(ft_strlen(*old), sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (old[0][++i])
		new[i - 1] = (char)(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
