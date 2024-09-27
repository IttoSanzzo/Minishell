/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrem_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:41:54 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:41:55 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrem_n(char **old, int n)
{
	int		end;
	int		i;
	char	*new;

	if (!*old || n < 0)
		return (NULL);
	end = ft_strlen(*old);
	if (!old[0][0] || n > end - 1)
		return (*old);
	new = (char *)ft_calloc(end, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[0][++i] && i < n)
		new[i] = (char)(old[0][i]);
	while (old[0][++i])
		new[i - 1] = (char)(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
