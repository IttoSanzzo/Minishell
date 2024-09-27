/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfreeitab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:06:34 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 10:11:39 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_nfreeitab(int ***itab)
{
	int	i;

	i = -1;
	if (!*itab)
		return (NULL);
	while (itab[0][++i])
		ft_free(itab[0][i]);
	if (itab)
		ft_free(*itab);
	*itab = NULL;
	return (*itab);
}
