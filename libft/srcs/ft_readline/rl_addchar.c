/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:56 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:32:00 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rl_putt(t_readline *rl)
{
	int	save[2];

	ft_ansi_drd(NULL);
	rl->pos = rl->spos;
	if (rl->vpos)
	{
		ft_putclst_xfory(rl->line, rl->pos, rl->vpos);
		rl_getcp(&save[0], &save[1], rl);
		ft_putclstpos(rl->line, rl->pos + rl->vpos);
		rl->pos += rl->vpos;
	}
	else
	{
		rl_getcp(&save[0], &save[1], rl);
		ft_putclstpos(rl->line, rl->pos);
	}
	rl_save_end(rl);
	ft_ansi_go(save[0], save[1]);
	rl_go_right(rl);
	rl->spos = -1;
	rl->vpos = 0;
}

void	rl_addchar(t_readline *rl)
{
	ft_clstadd_n(&rl->line, ft_clstnew(rl->ch), rl->pos + rl->vpos);
	rl->len++;
	if (rl->spos == -1)
		rl->spos = rl->pos;
	if (rl->buffer)
		rl->vpos++;
	if (!rl->buffer)
		rl_putt(rl);
}
