/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:42:14 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:42:15 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(char **old, char add)
{
	if (*old)
		return (*old);
	*old = (char *)ft_calloc(2, sizeof(char));
	if (!*old)
		return (NULL);
	old[0][0] = (char)(add);
	return (*old);
}
