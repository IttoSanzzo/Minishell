/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:42:19 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:42:20 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strins_len(char *old, char *add)
{
	int	len;

	len = ft_strlen(old);
	len += ft_strlen(add);
	return (len);
}

char	*ft_strins_n(char **old, char *add, int n)
{
	int		i;
	int		y;
	char	*new;

	if (n < 0 || !*old)
		return (NULL);
	new = (char *)ft_calloc(strins_len(*old, add) + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (old[0][++i] && i < n)
		new[i] = (char)(old[0][i]);
	y = -1;
	while (add && add[++y])
		new[i + y] = (char)(add[y]);
	if (!add)
		y = 0;
	i--;
	while (old[0][++i])
		new[i + y] = (char)(old[0][i]);
	free(*old);
	*old = new;
	return (new);
}
