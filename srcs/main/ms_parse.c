/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_parse.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 05:36:42 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 21:10:56 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_check_allspc(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}

static int	ms_check_entry(t_mini *ms)
{
	int	ret;

	ret = 0;
	if (ft_cquotes(ms->line) == 1 && ++ret)
		ms->altprompt = ft_strdup(ERR_SQUO);
	else if (ft_cquotes(ms->line) == 2 && ++ret)
		ms->altprompt = ft_strdup(ERR_DQUO);
	else if (ft_cend(ms->line) == 1 && ++ret)
		ms->altprompt = ft_strdup(ERR_CEND);
	return (ret);
}

static void	ms_readcmdl(t_mini *ms)
{
	char	*su;

	ms->sig.sint = 0;
	ms_gen_prompt(ms);
	ms_free_cmd(ms);
	ms->line = ms_readline(ms->prompt);
	if (!ms->line)
		ms_endlexit();
	if (ms->sig.sint || !ms->line[0])
		return (ms_readcmdl(ms));
	while (ms_check_entry(ms))
	{
		su = ms_readline(ms->altprompt);
		ft_nfreestr(&ms->altprompt);
		if (!su)
			ms_endlexit();
		if (ms->line)
		{
			ft_sujoin(&ms->line, "\n");
			ft_freejoin(&ms->line, &su);
		}
		if (ms->sig.sint)
			return (ms_readcmdl(ms));
	}
	ms_add_history(ms->line);
}

void	ms_parse(t_mini *ms)
{
	ms_free_vex(ms);
	ms_readcmdl(ms);
	if (ms_check_allspc(ms->line) || ms_check_tokens(ms))
		return (ms_parse(ms));
	ms_format_line(ms);
	ms->cmdl = ft_splitq(ms->line);
	ms_gen_vex(ms);
	if (ms_redirects(ms))
		return (ms_parse(ms));
}
