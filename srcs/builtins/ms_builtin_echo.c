/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtin_echo.c                                  :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/08 02:12:44 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 14:45:58 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

int	ms_builtin_echo(t_vars *vex)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (vex->av[1] && !ft_strncmp(vex->av[1], "-n", 3) && ++i)
		flag = 1;
	while (vex->av[++i])
	{
		ft_putstr(vex->av[i]);
		if (vex->av[i + 1])
			ft_putchar(' ');
	}
	if (!flag)
		ft_putchar('\n');
	return (ms_ret(0));
}
