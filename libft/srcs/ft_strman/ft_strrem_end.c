/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:41:59 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:42:03 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrem_end(char **old)
{
	int		i;
	int		end;
	char	*new;

	if (!*old)
		return (NULL);
	if (!old[0][0])
		return (*old);
	end = ft_strlen(*old);
	new = (char *)ft_calloc(end, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < end - 1)
		new[i] = (char)(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
