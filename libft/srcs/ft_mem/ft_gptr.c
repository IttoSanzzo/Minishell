/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_gptr.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/27 21:17:31 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 04:18:17 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	*ft_gptr(int id, void *ptr)
{
	static void	*save[GMEM_BUFFER];

	if (id < 0 || id > GMEM_BUFFER - 1)
		return (NULL);
	if (ptr != GETV)
		save[id] = ptr;
	return (save[id]);
}
