/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:27:27 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:27:29 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gint(int id, size_t act, int val)
{
	static int	save[GMEM_BUFFER];

	if (id < 0 || id > GMEM_BUFFER - 1)
		return (0);
	if (act == PUTV)
		save[id] = val;
	return (save[id]);
}
