/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_redirects.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/11 17:18:03 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 18:14:34 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static void	ms_found_outfile(t_vars *vex, int i, int type)
{
	vex->outp = type;
	vex->ac -= 2;
	ft_tabrem_n(&vex->av, i);
	ft_nfreestr(&vex->oufile);
	vex->oufile = ft_strdup(vex->av[i]);
	ft_strrem_qbl(&vex->oufile);
	ft_tabrem_n(&vex->av, i);
}

static void	ms_found_infile(t_vars *vex, int i)
{
	vex->intp = IN_FILE;
	vex->ac -= 2;
	ft_tabrem_n(&vex->av, i);
	ft_nfreestr(&vex->infile);
	vex->infile = ft_strdup(vex->av[i]);
	ft_strrem_qbl(&vex->infile);
	ft_tabrem_n(&vex->av, i);
}

int	ms_redirects(t_mini *ms)
{
	int	y;
	int	i;

	y = -1;
	ms->hds = 0;
	while (ms->vex[++y])
	{
		i = -1;
		while (ms->vex[y]->av[++i])
		{
			if (ms_is_token(ms->vex[y]->av[i]) == 2)
				ms_found_outfile(ms->vex[y], i--, OUT_AP);
			else if (ms_is_token(ms->vex[y]->av[i]) == 4)
				ms_found_outfile(ms->vex[y], i--, OUT_NP);
			else if (ms_is_token(ms->vex[y]->av[i]) == 3)
			{
				ms_found_hdoc(ms, ms->vex[y], i--);
				if (ms->sig.sint)
					return (ms->sig.sint);
			}
			else if (ms_is_token(ms->vex[y]->av[i]) == 5)
				ms_found_infile(ms->vex[y], i--);
		}
	}
	return (0);
}
