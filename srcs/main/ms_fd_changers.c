/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_fd_changers.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/17 15:11:10 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 17:09:26 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

void	ms_dup2(int new, int target)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	dup2(new, target);
	ms->cfd[target] = new;
}

void	ms_dup2c(int new, int target)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	dup2(new, target);
	ms->cfd[target] = new;
	close(new);
}

void	ms_reset_fds(int fd)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	if (fd == 0 || fd == 2)
	{
		dup2(ms->std[STDIN], STDIN);
		ms->cfd[STDIN] = ms->std[STDIN];
	}
	if (fd == 1 || fd == 2)
	{
		dup2(ms->std[STDOUT], STDOUT);
		ms->cfd[STDOUT] = ms->std[STDOUT];
	}
}
