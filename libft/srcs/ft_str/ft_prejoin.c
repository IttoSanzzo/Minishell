/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prejoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:35:12 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:35:13 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prejoin(char *s1, char **s2)
{
	char	*prejoin;

	prejoin = ft_strjoin(s1, *s2);
	if (*s2)
		free(*s2);
	*s2 = prejoin;
	return (prejoin);
}
