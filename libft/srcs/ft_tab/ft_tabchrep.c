/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabchrep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:11:01 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 11:16:11 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabchrep(char **tab, char trg, char rep)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_strchrep(tab[i], trg, rep);
}
