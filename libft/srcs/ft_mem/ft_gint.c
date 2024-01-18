/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_gint.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 21:17:31 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 04:17:50 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_gint(int id, size_t act, int val)
{
	static int	save[GMEM_BUFFER];

	if (id < 0 || id > GMEM_BUFFER - 1)
		return (0);
	if (act == PUTV)
		save[id] = val;
	return (save[id]);
}
