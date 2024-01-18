/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_utils.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:35:22 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/09 23:35:08 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_get_back(t_readline *rl)
{
	int	save;

	if (rl->pos == rl->len)
		return ;
	save = rl->pos;
	if (rl->pos >= rl->len % 2)
	{
		rl->pos = rl->len;
		while (rl->pos != save)
			rl_go_left(rl);
	}
	else
	{
		rl_go_home(rl);
		while (rl->pos != save)
			rl_go_right(rl);
	}
}

void	rl_cleard(t_readline *rl)
{
	ft_ansi_dfd();
	if (rl->prompt)
		ft_putstr((char *)rl->prompt);
	rl_save_home(rl);
	ft_putclst(rl->line);
	rl_save_end(rl);
	rl_get_back(rl);
}

char	rl_bufferuse(t_readline *rl)
{
	if (!rl->buffer)
		rl->ch = 0;
	else
	{
		rl->ch = rl->buffer->val;
		ft_clstrem_bgn(&rl->buffer);
	}
	return (rl->ch);
}

void	rl_termios_ch(int opt)
{
	static struct termios	oldt;
	struct termios			newt;

	if (opt == 0)
	{
		tcgetattr(STDIN_FILENO, &oldt);
		newt = oldt;
		newt.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	}
	if (opt == 1)
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
