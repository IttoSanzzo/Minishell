/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_check_tokens.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/09 04:24:26 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/12 01:21:48 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_get_obj(char *token, char **obj)
{
	if (!token[0])
		*obj = ft_strdup("\\n");
	else if (token[0] == ';')
		*obj = ft_strdup(";");
	else if (token[0] == '&' && token[1] == '&')
		*obj = ft_strdup("&&");
	else if (token[0] == '&')
		*obj = ft_strdup("&");
	else if (token[0] == '<' && token[1] == '<')
		*obj = ft_strdup("<<");
	else if (token[0] == '<')
		*obj = ft_strdup("<");
	else if (token[0] == '>' && token[1] == '>')
		*obj = ft_strdup(">>");
	else if (token[0] == '>')
		*obj = ft_strdup(">");
	else if (token[0] == '|' && token[1] == '|')
		*obj = ft_strdup("||");
	else if (token[0] == '|')
		*obj = ft_strdup("|");
}

static int	ms_mtoken(char *line, int *i)
{
	int	open;
	int	tc;

	tc = 0;
	open = 0;
	if (ft_strchr(TOKENS, line[0]))
		return (*i++ + 1);
	while (line[++i[0]])
	{
		if (!ft_strchr(TOKENS, line[*i]))
			tc = 0;
		if (((*i > 0 && line[*i - 1] == '\\') || ft_squotes(line, &open, *i)))
			continue ;
		else if (ft_strchr(DTOKENS, line[*i])
			&& (line[*i + 1] != line[*i] && line[*i - 1] != line[*i]))
			return (1);
		else if (ft_strchr(TOKENS, line[*i]))
			tc++;
		if (tc == 3)
			return (1);
	}
	*i = -1;
	return (0);
}

static int	ms_token_test(char *line, int *i, int token, int open)
{
	int	tc;

	tc = 0;
	while (line[++i[0]])
	{
		if (((*i > 0 && line[*i - 1] == '\\') || ft_squotes(line, &open, *i)))
		{
			token = 0;
			continue ;
		}
		else if (*i > 0 && (line[*i] == line[*i - 1])
			&& ft_strchr(TOKENS, line[*i]) && line[*i] != ';' && ++tc && tc < 3)
			continue ;
		else if (tc > 2 || (token > 0 && !open && ft_strchr(TOKENS, line[*i])))
			break ;
		else if (!open && ft_strchr(TOKENS, line[*i]) && ++tc)
			token = 1;
		else if (line[*i] != ' ' && line[*i] != '\n')
		{
			token = 0;
			tc = 0;
		}
	}
	return (token);
}

static int	ms_token_error(char **obj)
{
	ft_putstr_fd(TOKEN_ERR_A, STDERR);
	ft_putstr_fd(*obj, STDERR);
	ft_putstr_fd(TOKEN_ERR_B, STDERR);
	ft_nfreestr(&*obj);
	return (1);
}

int	ms_check_tokens(t_mini *ms)
{
	int		i;
	char	*obj;

	i = -1;
	obj = NULL;
	if (ms_mtoken(ms->line, &i) || ms_token_test(ms->line, &i, 1, 0))
		ms_get_obj((char *)(ms->line + i), &obj);
	if (obj && !ft_strncmp(obj, "\\n", 3))
	{
		i--;
		while (i > 0 && (ms->line[i] == ' ' || ms->line[i] == '\n'))
			i--;
		if (ms->line[i] == ';')
			ft_nfreestr(&obj);
	}
	if (obj)
		return (ms_token_error(&obj));
	return (0);
}
