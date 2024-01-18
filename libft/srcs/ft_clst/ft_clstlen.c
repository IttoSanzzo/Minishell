/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstlen.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:38:13 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 23:44:24 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_clstlen(t_clist *lst)
{
	t_clist	*last;
	int		i;

	last = lst;
	i = 0;
	while (last)
	{
		last = last->next;
		i++;
	}
	return (i);
}
