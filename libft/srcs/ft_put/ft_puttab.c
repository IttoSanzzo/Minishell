/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:29:41 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:29:43 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char **tab, char *prompt)
{
	int	i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
	{
		if (prompt)
			ft_putstr(prompt);
		ft_putendl(tab[i]);
	}
}
