/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/08 14:26:21 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 16:20:28 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

void	ms_sig_init(t_mini *ms)
{
	ms->sig.exit_status = 0;
	ms->sig.squit = 0;
	ms->sig.sint = 0;
	ms->sig.code = 0;
	ms->sig.pid = 0;
}

void	ms_sigint(int signum)
{
	t_mini	*ms;

	(void)signum;
	ms = ms_get_mini(NULL);
	if (ms->sig.pid != 0)
	{
		ms->sig.exit_status = 1;
		ms->ret = 1;
	}
	else
	{
		ft_ungetchar('\n');
		ms->sig.exit_status = 130;
	}
	ms->sig.sint = 1;
}

void	ms_sigquit(int signum)
{
	char	*nbr;
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	nbr = ft_itoa(signum);
	if (ms->sig.pid != 0)
	{
		ft_putstr_fd("Quit: ", STDERR);
		ft_putendl_fd(nbr, STDERR);
		ms->sig.exit_status = 131;
		ms->sig.squit = 1;
	}
	else
		ft_putstr_fd("", STDERR);
	ft_memdel(nbr);
}
