/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:02:53 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 17:34:20 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static char	*rl_wrap_up(t_readline *rl)
{
	char	*str;

	rl_checkmove(rl);
	str = ft_cltos(rl->line);
	ft_freeclst(&rl->line);
	rl_termios_ch(1);
	rl_go_end(rl);
	ft_putchar('\n');
	if (rl->ch == '\n' && !str)
		return (ft_strdup(""));
	return (str);
}
/*	if (!ft_rlconfig(3, GETV, 0))
		return (str);
	ft_rlconfig(3, PUTV, 0);
	ft_rlconfig(4, PUTV, 1);
	while (!ft_cquotes(str))
	{
		ft_stradd_end(&str, '\n');
		str = ft_freejoin(str, ft_readline("> "));
		if (str)
			break ;
	}
	ft_rlconfig(4, PUTV, 0);
	ft_rlconfig(3, PUTV, 1);
	if (ft_rlconfig(2, GETV, 0))
		return (ft_readline(rl->prompt));
	return (str);
}*/

char	ft_buffer_read(t_readline *rl)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (rl->buffer)
		return (rl_bufferuse(rl));
	rl->ch = ft_getchar();
	c = ft_getchar_unb(0);
	if (c == '\0')
		return (rl->ch);
	ft_clstadd_end(&rl->buffer, ft_clstnew(rl->ch));
	while (c != '\0')
	{
		ft_clstadd_end(&rl->buffer, ft_clstnew(c));
		c = ft_getchar_unb((i++ > 5));
	}
	return (rl_bufferuse(rl));
}

void	rl_init(t_readline *rl, const char *prompt)
{
	ft_freeclst(&rl->line);
	rl->buffer = NULL;
	rl->move = 0;
	rl->his = ft_add_history(NULL);
	rl->hlen = ft_rlconfig(0, GETV, 0);
	rl->hpos = rl->hlen;
	rl->spos = -1;
	rl->vpos = 0;
	rl->pos = 0;
	rl->len = 0;
	rl->ch = 0;
	rl->home[0] = 0;
	rl->home[1] = 0;
	rl->end[0] = 0;
	rl->end[1] = 0;
	rl->prompt = prompt;
	if (rl->prompt && !ft_rlconfig(2, GETV, 0))
		ft_putstr((char *)rl->prompt);
	ft_rlconfig(2, PUTV, 0);
	rl->ch = ft_buffer_read(rl);
	rl_save_home(rl);
	ft_ansi_sc();
}

static void	rl_others(t_readline *rl)
{
	if (rl->ch == '\033')
		rl_get_specials(rl);
	else if (rl_checkmove(rl) && rl->ch == '\t')
		rl_do_tab(rl);
	else if (rl->ch == 127 || rl->ch == 8)
		rl_do_backspace(rl);
	else if (rl->ch == '\f')
		rl_cleard(rl);
	else if (rl->ch == 11)
		rl->ch = rl->ch;
	else if (rl->ch != '\n' && rl->ch != 4)
		rl_addchar(rl);
}

char	*ft_readline(const char *prompt)
{
	int			iters;
	t_readline	rl;

	rl_termios_ch(0);
	rl.line = NULL;
	rl_init(&rl, prompt);
	iters = 0;
	while (rl.ch != '\n' && ++iters)
	{
		if (!rl_checkreset(&rl) && iters != 1)
			rl.ch = ft_buffer_read(&rl);
		if (rl_checkreset(&rl) == 2)
			return (NULL);
		else if (rl_checkreset(&rl) == 1 || rl.ch == 0)
			continue ;
		if (rl.len == 0 && rl.ch == 4)
			return ((char *)ft_freeclst(&rl.line));
		else
			rl_others(&rl);
	}
	return (rl_wrap_up(&rl));
}
