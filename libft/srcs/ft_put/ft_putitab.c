/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putitab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:53:04 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 19:01:16 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putitab(int **tab, char *prompt, char *divider, int stop)
{
	int	i;
	int	y;

	if (!tab)
		return ;
	y = -1;
	while (tab[++y])
	{
		i = -1;
		if (prompt)
			ft_putstr(prompt);
		while (tab[y][++i] != stop)
		{
			ft_putnbr(tab[y][i]);
			if (divider && tab[y][i + 1] != stop)
				ft_putstr(divider);
		}
		ft_endl(1);
	}
}
