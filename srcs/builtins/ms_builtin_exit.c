/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtin_exit.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/04 14:38:29 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 21:22:17 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

void	ms_free_vex(t_mini *ms)
{
	int	i;

	if (ms->vex)
	{
		i = -1;
		while (ms->vex[++i])
		{
			ft_nfreestr(&ms->vex[i]->hdoc);
			ft_nfreestr(&ms->vex[i]->infile);
			ft_nfreestr(&ms->vex[i]->oufile);
			ft_nfreestr(&ms->vex[i]->path);
			ft_nfreestr(&ms->vex[i]->cmd);
			ft_nfreetab(&ms->vex[i]->av);
			ft_nfree((void *)&ms->vex[i]);
		}
		ft_nfree((void *)&ms->vex);
	}
}

void	ms_free_cmd(t_mini *ms)
{
	ft_nfreestr(&ms->line);
	ft_nfreetab(&ms->cmdl);
}

void	ms_exec_exit(int ret)
{
	ms_freeall();
	ms_rl_clear_history();
	exit(ret);
}

int	ms_builtin_exit(t_vars *vex)
{
	(void)vex;
	ms_freeall();
	ms_rl_clear_history();
	ft_putstr(EXIT_MSS);
	exit(EXIT_SUCC);
	return (0);
}

void	ms_endlexit(void)
{
	if (READLINE != 1)
		ft_putchar('\n');
	ms_builtin_exit(NULL);
}
