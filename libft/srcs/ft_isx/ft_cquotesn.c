/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cquotesn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:21:16 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:21:17 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cquotesn(char *s, int n)
{
	int	i;
	int	open;

	i = -1;
	open = 0;
	if (!s || n < 0)
		return (0);
	while (s[++i] && i < n)
	{
		if (i > 0 && s[i - 1] == '\\')
			continue ;
		else if (open == 0 && s[i] == '\"')
			open = 2;
		else if (open == 0 && s[i] == '\'')
			open = 1;
		else if (open == 2 && s[i] == '\"')
			open = 0;
		else if (open == 1 && s[i] == '\'')
			open = 0;
	}
	return (open);
}
