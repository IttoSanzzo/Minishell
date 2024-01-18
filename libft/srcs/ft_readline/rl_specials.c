/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_specials.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:37:55 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/09 23:32:21 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_do_tab(t_readline *rl)
{
	(void)rl;
	if (ft_rlconfig(1, GETV, 0))
		return ;
}

void	rl_do_backspace(t_readline *rl)
{
	if (rl->pos > 0)
	{
		ft_clstrem_n(&rl->line, rl->pos - 1);
		rl->len--;
		rl_go_left(rl);
		ft_ansi_drd(NULL);
		ft_putclstpos(rl->line, rl->pos);
		rl_save_end(rl);
		rl_get_back(rl);
	}
}

static void	rl_do_insert(t_readline *rl)
{
	rl->ch = '[';
	rl_addchar(rl);
	rl->ch = '2';
	rl_addchar(rl);
	rl->ch = '~';
	rl_addchar(rl);
}

static void	rl_do_delete(t_readline *rl)
{
	if (rl->pos < rl->len)
	{
		ft_clstrem_n(&rl->line, rl->pos);
		rl->len--;
		ft_ansi_drd(NULL);
		ft_putclstpos(rl->line, rl->pos);
		rl_save_end(rl);
		rl_get_back(rl);
	}
}

void	rl_get_specials(t_readline *rl)
{
	if ('[' == rl_bufferuse(rl))
	{
		rl->ch = rl_bufferuse(rl);
		if (rl->ch == 'A' || rl->ch == 'B' || rl->ch == 'C' || rl->ch == 'D'
			|| rl->ch == 'H' || rl->ch == 'F')
			rl_do_moviments(rl);
		else if (rl_checkmove(rl) && (rl->ch == '2')
			&& rl_bufferuse(rl) == '~')
			rl_do_insert(rl);
		else if ((rl->ch == '3') && (rl_bufferuse(rl) == '~'))
			rl_do_delete(rl);
	}
}
