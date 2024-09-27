/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:51 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:31:52 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rl_checkmove(t_readline *rl)
{
	if (rl->move)
	{
		ft_freeclst(&rl->line);
		rl->line = ft_stocl(rl->his[rl->hpos]);
		rl->hpos = rl->hlen;
		rl->move = 0;
	}
	return (1);
}

int	rl_checkreset(t_readline *rl)
{
	static int	safety;

	if (ft_rlconfig(4, GETV, 0) != 2 && safety > 0)
	{
		safety--;
		return (safety);
	}
	else if (ft_rlconfig(2, GETV, 0))
	{
		rl_checkmove(rl);
		ft_ungetchar(rl->ch);
		ft_freeclst(&rl->buffer);
		if (ft_rlconfig(4, GETV, 0))
		{
			ft_freeclst(&rl->line);
			return (2);
		}
		rl_init(rl, rl->prompt);
		safety = 2;
		return (1);
	}
	return (0);
}
