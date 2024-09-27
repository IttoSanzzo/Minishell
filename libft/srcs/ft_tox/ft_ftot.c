/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:56:03 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 10:02:48 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ftot(char *file, char ***output, char c)
{
	char	*temp;

	temp = NULL;
	if (!file || ft_ftos(file, &temp) == -1)
		return (-1);
	ft_nfreetab(output);
	*output = ft_split(temp, c);
	ft_nfreestr(&temp);
	return (0);
}
