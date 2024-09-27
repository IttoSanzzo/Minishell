/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:17 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:31:19 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_history(char *new)
{
	int			len;
	int			i;
	static char	**history;

	if (!new)
		return (history);
	if (!history)
	{
		history = (char **)ft_calloc(2, sizeof(char *));
		history[0] = ft_strdup(new);
		ft_rlconfig(0, PUTV, 1);
	}
	else
	{
		len = ft_tablen(history);
		i = (ft_getrstr_p(history, new));
		if (i != -1 && i != len - 1)
			ft_tabsmove(history, i, len - 1);
		else
		{
			history = ft_tabadd_end(&history, ft_strdup(new));
			ft_rlconfig(0, PUTV, len + 1);
		}
	}
	return (history);
}
