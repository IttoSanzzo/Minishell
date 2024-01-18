/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_found_hdoc.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/11 14:36:27 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 17:59:25 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_gen_hdoc_prompt(char **prompt, int hds)
{
	char	*nbr;

	nbr = NULL;
	nbr = ft_itoa(hds);
	*prompt = ft_strdup(HDOC_A);
	ft_freejoin(prompt, &nbr);
	ft_sujoin(prompt, HDOC_B);
}

static void	ms_hdoc_eof(char **line, char *end)
{
	ft_putstr(HDOC_EOF_A);
	ft_putstr(HDOC_EOF_B);
	ft_putstr(end);
	ft_putstr(HDOC_EOF_C);
	*line = ft_strdup(end);
}

static void	ms_get_hdoc(t_mini *ms, char *prompt, char **hdoc, char *end)
{
	char	*line;

	if (!*hdoc)
		*hdoc = ft_strdup("");
	line = NULL;
	while (ft_strncmp(line, end, ft_strlen(end) + 1) && !ms->sig.sint)
	{
		if (line)
		{
			ft_sujoin(hdoc, line);
			ft_sujoin(hdoc, "\n");
		}
		ft_nfreestr(&line);
		line = ms_readline(prompt);
		if (!line)
			ms_hdoc_eof(&line, end);
	}
	ft_nfreestr(&line);
}

void	ms_found_hdoc(t_mini *ms, t_vars *vex, int i)
{
	char	*prompt;

	vex->ac -= 2;
	vex->intp = IN_HDOC;
	prompt = NULL;
	ft_tabrem_n(&vex->av, i);
	ms->hds++;
	ms_gen_hdoc_prompt(&prompt, ms->hds);
	ms_get_hdoc(ms, prompt, &vex->hdoc, vex->av[i]);
	ft_nfreestr(&prompt);
	ft_tabrem_n(&vex->av, i);
}
