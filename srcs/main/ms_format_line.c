/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_format_line.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/09 20:57:21 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/14 13:02:32 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_check_bl(char *line, int i)
{
	if (i > 1 && (ft_strchr(TOKENS, line[i]) && line[i] == line[i - 1])
		&& (line[i - 2] == '\\'))
		return (1);
	if (i > 2 && (ft_strchr(TOKENS, line[i]) && line[i] == line[i - 1])
		&& (line[i - 3] == '\\'))
		return (1);
	return (0);
}

static int	ms_form_check(char c, int open, int *token, int *space)
{
	if (c == ' ' && !open)
	{
		if (!*token)
			*space = 1;
		return (1);
	}
	if (!open && !*token && ft_strchr(TOKENS, c))
	{
		*space = 0;
		*token = 1;
		return (2);
	}
	else if (*space)
	{
		*space = 0;
		return (2);
	}
	else if (*token && !(ft_strchr(TOKENS, c)))
	{
		*token = 0;
		return (2);
	}
	return (0);
}

static t_clist	*ms_form_tab(t_clist *form, char *line)
{
	int	token;
	int	space;
	int	open;
	int	ret;
	int	i;

	i = -1;
	ret = 0;
	open = 0;
	token = 0;
	space = 0;
	while (line[++i])
	{
		ft_squotes(line, &open, i);
		if (i > 0 && (line[i - 1] == '\\' || ms_check_bl(line, i)))
			ret = ms_form_check('\\', open, &token, &space);
		else
			ret = ms_form_check(line[i], open, &token, &space);
		if (ret == 1)
			continue ;
		else if (ret == 2 && !(i > 0 && line[i - 1] == '\\'))
			ft_clstadd_end(&form, ft_clstnew(' '));
		ft_clstadd_end(&form, ft_clstnew(line[i]));
	}
	return (form);
}

void	ms_format_line(t_mini *ms)
{
	int		i;
	t_clist	*form;

	i = ft_strlen(ms->line) - 1;
	while (i >= 0 && (ms->line[i] == ' ' || ms->line[i] == '\n'))
		i--;
	if (ms->line[i] != ';')
		ft_sujoin(&ms->line, " ;");
	else if (ms->line[i] == ';' && i > 0 && ms->line[i - 1] == '\\')
		ft_sujoin(&ms->line, " ;");
	form = NULL;
	form = ms_form_tab(form, ms->line);
	ft_strdrep(&ms->line, ft_cltos(form));
	ft_freeclst(&form);
}
