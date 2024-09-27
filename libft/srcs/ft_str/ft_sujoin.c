/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sujoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:32:53 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:33:07 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sujoin(char **s1, char *s2)
{
	char	*sujoin;

	sujoin = ft_strjoin(*s1, s2);
	if (*s1)
		free(*s1);
	*s1 = sujoin;
	return (sujoin);
}
