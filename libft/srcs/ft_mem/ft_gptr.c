/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:27:22 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:27:23 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gptr(int id, void *ptr)
{
	static void	*save[GMEM_BUFFER];

	if (id < 0 || id > GMEM_BUFFER - 1)
		return (NULL);
	if (ptr != GETV)
		save[id] = ptr;
	return (save[id]);
}
