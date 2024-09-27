/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:35:01 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:35:04 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wc_q(char **s)
{
	int	wcount;
	int	open;
	int	flag;
	int	bl;
	int	i;

	i = -1;
	bl = 0;
	open = 0;
	flag = 1;
	wcount = 0;
	while (s[0][++i])
	{
		if (ft_squotesbl(*s, &open, i, &bl) == 3)
			continue ;
		if (s[0][i] == ' ' && open == 0 && ++flag)
			s[0][i] = '\0';
		else if (s[0][i] && flag && ++wcount)
			flag = 0;
		bl = 0;
	}
	return (wcount);
}

char	**ft_splitq(char const *s)
{
	int		len;
	int		i;
	int		y;
	char	*temp;
	char	**tab;

	if (!s)
		return (NULL);
	temp = ft_strdup(s);
	len = wc_q(&temp);
	tab = (char **)ft_calloc(len + 1, sizeof(char *));
	y = -1;
	i = 0;
	while (temp && temp[i] == '\0' && len > 0)
		i++;
	while (tab && ++y < len)
	{
		tab[y] = ft_strdup((char *)(temp + i));
		while (temp[i])
			i++;
		while (!temp[i] && y < len - 1)
			i++;
	}
	ft_nfreestr(&temp);
	return (tab);
}
