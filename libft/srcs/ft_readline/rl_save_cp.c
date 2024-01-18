/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_save_cp.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 06:45:03 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/04 02:52:21 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static void	rl_getcp_pop(char **str, t_readline *rl, int i)
{
	char	c;

	while (1)
	{
		read(STDIN_FILENO, &c, 1);
		while (c != '\033')
		{
			ft_clstadd_end(&rl->buffer, ft_clstnew(c));
			read(STDIN_FILENO, &c, 1);
		}
		i = -1;
		while (!ft_isupp(c))
		{
			str[0][++i] = c;
			read(STDIN_FILENO, &c, 1);
		}
		str[0][++i] = c;
		str[0][++i] = '\0';
		if (str[0][i - 1] == 'R')
			return ;
		i = -1;
		while (str[0][++i])
			ft_clstadd_end(&rl->buffer, ft_clstnew(c));
	}
}

void	rl_getcp(int *x, int *y, t_readline *rl)
{
	char			cod[CP_BUFFER];
	char			*str;

	write(STDIN_FILENO, "\033[6n", 4);
	str = cod;
	rl_getcp_pop(&str, rl, 0);
	*y = ft_atoi(cod + 2);
	*x = ft_atoi(ft_strchr(cod, ';') + 1);
}

void	rl_save_home(t_readline *rl)
{
	rl_getcp(&rl->home[0], &rl->home[1], rl);
}

void	rl_save_end(t_readline *rl)
{
	rl_getcp(&rl->end[0], &rl->end[1], rl);
}
