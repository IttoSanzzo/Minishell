/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:32:47 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:32:49 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char **s1, char **s2)
{
	char	*freejoin;

	freejoin = ft_strjoin(*s1, *s2);
	if (*s1)
		free(*s1);
	if (*s2)
		free(*s2);
	*s1 = freejoin;
	return (freejoin);
}
