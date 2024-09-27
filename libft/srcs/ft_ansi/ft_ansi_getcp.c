/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ansi_getcp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:10:19 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:10:21 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ansi_getcp(int *x, int *y)
{
	struct termios	oldt;
	struct termios	newt;
	char			cod[CP_BUFFER];
	char			*str;
	char			c;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	write(STDIN_FILENO, "\033[6n", 4);
	read(STDIN_FILENO, &c, 1);
	str = cod;
	while (c != 'R')
	{
		*str++ = c;
		read(STDIN_FILENO, &c, 1);
	}
	*str = '\0';
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	*y = ft_atoi(cod + 2);
	*x = ft_atoi(ft_strchr(cod, ';') + 1);
}
