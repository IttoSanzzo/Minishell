/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_expand.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/16 22:51:34 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 03:17:34 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static int	ms_expand_got(char **arg, int i, t_mini *ms)
{
	int		len;
	char	*name;
	char	*exp;

	name = NULL;
	exp = NULL;
	len = 0;
	while (arg[0][i + len] && !ft_strchr(EXP_CHAR, arg[0][i + len])
		&& !((len == 0 && arg[0][i + len] == '?' && ++len)))
		len++;
	name = ft_strtrim_xtoy(*arg, i, i + len - 1);
	ft_strrem_qbl(&name);
	if (!ft_strncmp(name, "?", 2))
		exp = ft_itoa(ms->ret);
	else
		exp = ft_strdup(ft_getarg(ms->ep, ft_sujoin(&name, "=")));
	ft_nfreestr(&name);
	ft_strrem_xtoy(arg, i - 1, i + len - 1);
	ft_strins_n(arg, exp, i - 1);
	len = ft_strlen(exp);
	ft_nfreestr(&exp);
	return (len);
}

static void	ms_expand_core(char **arg, t_mini *ms)
{
	int	open;
	int	bl;
	int	i;

	open = 0;
	bl = 0;
	i = -1;
	while (arg[0][++i])
	{
		if (ft_squotesbl(*arg, &open, i, &bl) == 3)
			continue ;
		if (arg[0][i] == '$' && bl == 0 && open != 1)
			i += ms_expand_got(arg, i + 1, ms) - 1;
	}
}

void	ms_expand(t_vars *vex)
{
	int		i;
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	i = 0;
	while (vex->av[++i])
		ms_expand_core(&vex->av[i], ms);
}
