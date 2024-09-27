/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_gen_vex.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/11 03:28:15 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 13:05:32 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_vex_actp(t_mini *ms)
{
	int	y;

	y = -1;
	while (ms->vex[++y])
	{
		ms->vex[y]->ac = ft_tablen(ms->vex[y]->av) - 1;
		if (!ft_strncmp(ms->vex[y]->av[ms->vex[y]->ac], "|", 2))
			ms->vex[y]->tp = 0;
		else if (!ft_strncmp(ms->vex[y]->av[ms->vex[y]->ac], ";", 2))
			ms->vex[y]->tp = 1;
		else if (!ft_strncmp(ms->vex[y]->av[ms->vex[y]->ac], "&&", 3))
			ms->vex[y]->tp = 2;
		else if (!ft_strncmp(ms->vex[y]->av[ms->vex[y]->ac], "||", 3))
			ms->vex[y]->tp = 3;
		ft_tabrem_end(&ms->vex[y]->av);
	}
}

static void	ms_vex_avs(t_mini *ms)
{
	int	y;
	int	i;

	y = -1;
	i = -1;
	if (!ms->cmdl)
		return ;
	while (ms->vex[++y])
	{
		ms->vex[y]->av = (char **)ft_calloc(1, sizeof(char *));
		while (ms_is_token(ms->cmdl[++i]) != 1)
			ft_tabadd_end(&ms->vex[y]->av, ft_strdup(ms->cmdl[i]));
		ft_tabadd_end(&ms->vex[y]->av, ft_strdup(ms->cmdl[i]));
		ms->vex[y]->ep = ms->ep;
		ms->vex[y]->path = NULL;
		ms->vex[y]->cmd = NULL;
		ms->vex[y]->hdoc = NULL;
		ms->vex[y]->infile = NULL;
		ms->vex[y]->oufile = NULL;
		ms->vex[y]->intp = 0;
		ms->vex[y]->outp = 0;
	}
}

static int	ms_vex_count(char **cmdl)
{
	int	i;
	int	vc;

	if (!cmdl)
		return (0);
	i = -1;
	vc = 0;
	while (cmdl[++i])
		if (ms_is_token(cmdl[i]) == 1)
			vc++;
	return (vc);
}

void	ms_gen_vex(t_mini *ms)
{
	int	vc;
	int	i;

	vc = ms_vex_count(ms->cmdl);
	ms->vex = (t_vars **)ft_calloc(vc + 1, sizeof(t_vars *));
	if (!ms->vex)
		return ;
	i = -1;
	while (++i < vc)
		ms->vex[i] = (t_vars *)ft_calloc(1, sizeof(t_vars));
	ms_vex_avs(ms);
	ms_vex_actp(ms);
}
