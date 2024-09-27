/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nfreetab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:26:14 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:26:16 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_nfreetab(char ***mem)
{
	int	i;

	i = -1;
	if (!*mem)
		return (NULL);
	while (mem[0][++i])
		ft_free(mem[0][i]);
	if (mem)
		ft_free(*mem);
	*mem = NULL;
	return (*mem);
}
