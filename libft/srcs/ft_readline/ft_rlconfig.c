/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_rlconfig.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 03:53:02 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 22:04:35 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

// ID 0 = HISTORY LEN..: Used to check it's lenght, and defined by history funs;
// ID 1 = TAB FUNCTION..: Uses opendir(), readdir() and closedir();
// ID 2 = Force Reset..: Frees and resets the readline from outside;
// ID 3 = Quotation Test..: Keeps readline up until quotes are closed;
// ID 4 = IN Quotation..: Used to exit Quotation Closure Function;
int	ft_rlconfig(int id, size_t act, int val)
{
	static int	save[5];

	if (id < 0 || id > 5 - 1)
		return (0);
	if (act == PUTV)
		save[id] = val;
	return (save[id]);
}
