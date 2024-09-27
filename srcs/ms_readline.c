/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/16 17:50:36 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 18:19:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "minishell.h"

char	*ms_readline(char *prompt)
{
	if (READLINE)
		return (readline(prompt));
	return (ft_readline(prompt));
}

void	ms_add_history(char *line)
{
	if (READLINE)
		return (add_history(line));
	return ((void)ft_add_history(line));
}

void	ms_rl_clear_history(void)
{
	if (READLINE)
		return (rl_clear_history());
	return (ft_rl_clear_history());
}
