/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:45:27 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:45:29 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	do_sort_clockwise(char **tab, char *str, int start, int end)
{
	int		i;

	i = start - 1;
	while (++i < end)
		tab[i] = (char *)(tab[i + 1]);
	tab[i] = (char *)(str);
}

static void	do_sort_anticlockwise(char **tab, char *str, int start, int end)
{
	int		i;

	i = start + 1;
	while (--i > end)
		tab[i] = (char *)(tab[i - 1]);
	tab[i] = (char *)(str);
}

char	*ft_tabsmove(char **tab, int start, int end)
{
	int		tablen;
	char	*str;

	if (!tab)
		return (NULL);
	tablen = ft_tablen(tab);
	str = (char *)(tab[start]);
	if (end < 0 || start < 0 || end >= tablen || start >= tablen)
		return (NULL);
	else if (start == end)
		return (str);
	else if (start < end)
		do_sort_clockwise(tab, str, start, end);
	else
		do_sort_anticlockwise(tab, str, start, end);
	return (str);
}
