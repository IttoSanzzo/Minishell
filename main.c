/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: gupiment <gupiment@student.42.fr>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/04 13:36:45 by gupiment	       #+#    #+#	      */
/*   Updated: 2024/01/17 22:36:10 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_msvars(t_mini *ms)
{
	ms->home = ft_strdup(ft_getarg(ms->ep, "HOME="));
	if (!ms->home)
		ms->home = ft_strdup("/");
	ft_getcwd(&ms->pwd);
}

static void	minishell(t_mini *ms)
{
	int	i;

	i = -1;
	while (ms->vex && ms->vex[++i])
	{
		ms_vex_finish(ms, ms->vex[i]);
		if (i == 0)
			ms_redirects_finish(ms, ms->vex[i], NULL);
		else
			ms_redirects_finish(ms, ms->vex[i], ms->vex[i - 1]);
		if (ms->vex && ms_builtins_switch(ms->vex[i]))
			ms_exec_vex(ms, (t_vars *)ms->vex[i]);
		if (ms->sig.sint || ms->sig.squit || !ms->vex)
			break ;
	}
}

static void	ms_mini_init(t_mini *ms, char **ep)
{
	ms_get_mini(ms);
	ms->altprompt = NULL;
	ms->prompt = NULL;
	ms->line = NULL;
	ms->cmdl = NULL;
	ms->home = NULL;
	ms->pwd = NULL;
	ms->ret = 0;
	ms->exit = 0;
	ms->vex = NULL;
	ms->std[0] = dup(STDIN);
	ms->std[1] = dup(STDOUT);
	ms_dup2(ms->std[0], STDIN);
	ms_dup2(ms->std[1], STDOUT);
	ms->ep = ft_tabdup(ep);
	ms_msvars(ms);
}

int	main(int ac, char **av, char **ep)
{
	t_mini	ms;

	(void)ac;
	(void)av;
	ms_mini_init(&ms, ep);
	signal(SIGINT, &ms_sigint);
	signal(SIGQUIT, &ms_sigquit);
	while (ms.exit == 0)
	{
		ms_sig_init(&ms);
		ms_parse(&ms);
		minishell(&ms);
		ms_reset_fds(2);
	}
	return (ms.ret);
}
