/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:31:02 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 15:10:49 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

int	ms_is_token(char *cmd)
{
	if (!ft_strncmp(cmd, ";", 2)
		|| !ft_strncmp(cmd, "|", 2)
		|| !ft_strncmp(cmd, "||", 3)
		|| !ft_strncmp(cmd, "&&", 3))
		return (1);
	else if (!ft_strncmp(cmd, ">>", 3))
		return (2);
	else if (!ft_strncmp(cmd, "<<", 3))
		return (3);
	else if (!ft_strncmp(cmd, ">", 2))
		return (4);
	else if (!ft_strncmp(cmd, "<", 2))
		return (5);
	return (0);
}

t_mini	*ms_get_mini(t_mini *ms)
{
	static t_mini	*save;

	if (ms)
		save = ms;
	return (save);
}

void	ms_waitret(int pid, int *status, int options)
{
	waitpid(pid, status, options);
	if (*status == 32256 || *status == 32512)
		*status = *status / 256;
	else
		*status = !!*status;
}

void	ms_freeall(void)
{
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	ms_free_cmd(ms);
	ms_free_vex(ms);
	ft_nfreestr(&ms->prompt);
	ft_nfreestr(&ms->home);
	ft_nfreestr(&ms->pwd);
	ft_nfreetab(&ms->ep);
}
