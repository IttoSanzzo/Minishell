/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtin_unset.c                                 :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:13:15 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 14:50:09 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

int	ms_builtin_unset(t_vars *vex)
{
	int		i;
	int		p;
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	i = 0;
	p = -1;
	while (vex->av[++i])
	{
		if (vex->av[i][0])
		{
			ft_sujoin(&vex->av[i], "=");
			p = ft_getarg_p(vex->ep, vex->av[i]);
			if (p >= 0)
				ft_tabrem_n(&ms->ep, p);
		}
	}
	return (ms_ret(0));
}
