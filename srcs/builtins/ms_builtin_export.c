/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtin_export.c                                :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:13:15 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 18:46:49 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

static int	export_err(char *arg)
{
	ft_putstr_fd(XP_ERR_A, STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putstr_fd(XP_ERR_B, STDERR);
	return (1);
}

static int	ms_export_check(char *arg, int eq)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (ft_strchr(EXPORT_ERR, arg[i]))
		{
			arg[eq] = '=';
			return (1);
		}
	}
	return (0);
}

int	ms_export_core(t_mini *ms, char *arg)
{
	int		eq;
	int		p;

	eq = ft_strchp(arg, '=');
	if (eq == -1)
		return (1);
	if (eq == 0 || arg[eq - 1] == '\\')
		return (export_err(arg));
	arg[eq] = '\0';
	if (ms_export_check(arg, eq))
		return (export_err(arg));
	p = ft_getarg_p(ms->ep, arg);
	arg[eq] = '=';
	if (p != -1)
		ft_strdrep(&ms->ep[p], ft_strdup(arg));
	else
		ft_tabadd_end(&ms->ep, ft_strdup(arg));
	return (0);
}

int	ms_builtin_export(t_vars *vex)
{
	int		i;
	int		ret;
	t_mini	*ms;

	ms = ms_get_mini(NULL);
	if (vex->ac == 1)
	{
		ft_puttab(vex->ep, EXPORT_STDMSS);
		return (ms_ret(0));
	}
	ret = 0;
	i = 0;
	while (vex->av[++i])
		if (vex->av[i][0])
			ret += ms_export_core(ms, (char *)vex->av[i]);
	return (ms_ret(!!ret), 0);
}
