/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_squotesbl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:20:21 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:20:24 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_squotesbl(char *line, int *open, int i, int *bl)
{
	if (*open != 1 && line[i] == '\\' && !*bl)
	{
		*bl = 1;
		return (3);
	}
	else if (*bl)
		return (0);
	else if (line[i] == '\"' || line[i] == '\'')
	{
		if (*open == 0 && line[i] == '\"')
			*open = 2;
		else if (*open == 0 && line[i] == '\'')
			*open = 1;
		else if (*open == 2 && line[i] == '\"')
			*open = 0;
		else if (*open == 1 && line[i] == '\'')
			*open = 0;
		return (1);
	}
	return (0);
}
