/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_builtins_switch.c                               :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 14:43:29 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 14:47:48 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

int	ms_builtins_switch(t_vars *vex)
{
	if (!ft_strncmp(vex->av[0], "echo", 5))
		return (ms_builtin_echo(vex));
	if (!ft_strncmp(vex->av[0], "cd", 3))
		return (ms_builtin_cd(vex));
	if (!ft_strncmp(vex->av[0], "pwd", 4))
		return (ms_builtin_pwd(vex));
	if (!ft_strncmp(vex->av[0], "export", 7))
		return (ms_builtin_export(vex));
	if (!ft_strncmp(vex->av[0], "unset", 6))
		return (ms_builtin_unset(vex));
	if (!ft_strncmp(vex->av[0], "env", 4))
		return (ms_builtin_env(vex));
	if (!ft_strncmp(vex->av[0], "exit", 5))
		return (ms_builtin_exit(vex));
	return (1);
}
