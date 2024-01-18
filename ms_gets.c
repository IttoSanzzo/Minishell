/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_gets.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 04:34:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 22:42:35 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_home(void)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	return (ms->home);
}

char	*ms_pwd(void)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	return (ms->pwd);
}

int	ms_ret(int ret)
{
	static t_mini	*ms;

	if (!ms)
		ms = ms_get_mini(NULL);
	ms->ret = ret;
	return (ret);
}
