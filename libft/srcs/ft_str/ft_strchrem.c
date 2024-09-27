/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:32:34 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 16:59:56 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrl(char *str, char c)
{
	int	i;
	int	l;

	i = -1;
	l = 0;
	while (str[++i])
		if (str[i] != c)
			l++;
	return (l + 1);
}

char	*ft_strchrem(char **str, char c)
{
	char	*ret;
	int		i;
	int		j;

	if (!*str)
		return (NULL);
	i = -1;
	j = -1;
	ret = ft_calloc(ft_chrl(*str, c), sizeof(char));
	while (str[0][++i])
		if (str[0][i] != c)
			ret[++j] = str[0][i];
	ft_nfreestr(str);
	*str = ret;
	return (ret);
}
