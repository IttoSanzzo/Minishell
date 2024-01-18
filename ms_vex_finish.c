/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_vex_finish.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/12 00:38:25 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 22:56:56 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_getavn(char **name)
{
	int		i;
	char	*temp;

	i = ft_strlen(*name) - 1;
	while (i >= 1 && name[0][i - 1] != '/')
		i--;
	temp = ft_strdup((char *)&name[0][i]);
	ft_nfreestr(name);
	*name = temp;
}

void	ms_vex_finish(t_mini *ms, t_vars *vex)
{
	(void)ms;
	ms_expand(vex);
	ft_tabrem_qbl(vex->av);
	vex->cmd = ft_strdup(vex->av[0]);
	ms_getavn(&vex->av[0]);
}
