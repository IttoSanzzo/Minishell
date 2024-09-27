/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_moviments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:40 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:31:41 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rl_go_home(t_readline *rl)
{
	if (rl->pos > 0)
	{
		ft_ansi_go(rl->home[0], rl->home[1]);
		rl->pos = 0;
	}
}

void	rl_go_end(t_readline *rl)
{
	if (rl->pos < rl->len)
	{
		ft_ansi_go(rl->end[0], rl->end[1]);
		rl->pos = rl->len;
	}
}

static void	rl_do_arrow_up(t_readline *rl)
{
	if (rl->his && rl->hpos > 0)
	{
		rl_go_home(rl);
		ft_ansi_drd(NULL);
		rl->hpos--;
		ft_putstr(rl->his[rl->hpos]);
		rl_save_end(rl);
		rl->len = ft_strlen(rl->his[rl->hpos]);
		rl->pos = rl->len;
		rl->move = 1;
	}
}

static void	rl_do_arrow_down(t_readline *rl)
{
	if (rl->his && rl->hpos < rl->hlen)
	{
		rl_go_home(rl);
		ft_ansi_drd(NULL);
		rl->hpos++;
		if (rl->hpos == rl->hlen)
		{
			ft_putclst(rl->line);
			rl_save_end(rl);
			rl->len = ft_clstlen(rl->line);
			rl->pos = rl->len;
			rl->move = 0;
		}
		else
		{
			ft_putstr(rl->his[rl->hpos]);
			rl_save_end(rl);
			rl->len = ft_strlen(rl->his[rl->hpos]);
			rl->pos = rl->len;
			rl->move = 1;
		}
	}
}

void	rl_do_moviments(t_readline *rl)
{
	if (rl->ch == 'A')
		rl_do_arrow_up(rl);
	else if (rl->ch == 'B')
		rl_do_arrow_down(rl);
	else if ((rl->ch == 'D') && (rl->pos > 0))
		rl_go_left(rl);
	else if ((rl->ch == 'C') && (rl->pos < rl->len))
		rl_go_right(rl);
	else if (rl->ch == 'H')
		rl_go_home(rl);
	else if (rl->ch == 'F')
		rl_go_end(rl);
}
