/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:44 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:31:46 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rl_force_end(t_readline *rl)
{
	int	bfr[2];
	int	aft[2];

	rl_getcp(&bfr[0], &bfr[1], rl);
	ft_printf("\033[%dC", RL_FORCE_END);
	rl_getcp(&aft[0], &aft[1], rl);
	if (bfr[0] != aft[0])
	{
		bfr[0] = aft[0];
		ft_printf("\033[%dC", RL_FORCE_END);
		rl_getcp(&aft[0], &aft[1], rl);
	}
}

void	rl_go_right(t_readline *rl)
{
	int	bfr[2];
	int	aft[2];

	if (rl->pos < rl->len)
	{
		rl_getcp(&bfr[0], &bfr[1], rl);
		ft_putstr("\033[C");
		rl_getcp(&aft[0], &aft[1], rl);
		if (bfr[0] == aft[0])
			ft_putstr("\033[1E");
		rl->pos++;
	}
}

void	rl_go_left(t_readline *rl)
{
	int	bfr[2];
	int	aft[2];

	if (rl->pos > 0)
	{
		rl_getcp(&bfr[0], &bfr[1], rl);
		ft_putstr("\033[D");
		rl_getcp(&aft[0], &aft[1], rl);
		if (bfr[0] == aft[0])
		{
			ft_putstr("\033[1F");
			rl_force_end(rl);
		}
		rl->pos--;
	}
}
