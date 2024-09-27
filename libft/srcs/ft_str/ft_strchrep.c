/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:06:00 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 11:11:33 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchrep(char *str, char trg, char rep)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		if (str[i] == trg)
			str[i] = rep;
}
