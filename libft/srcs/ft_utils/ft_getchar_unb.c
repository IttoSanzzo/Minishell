/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getchar_unb.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/28 00:18:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 16:32:03 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_getchar_unb(int dsecs)
{
	struct termios	oldt;
	struct termios	newt;
	int				c;

	c = '\0';
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	newt.c_cc[VMIN] = 0;
	newt.c_cc[VTIME] = dsecs;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	read(STDIN_FILENO, &c, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return (c);
}
