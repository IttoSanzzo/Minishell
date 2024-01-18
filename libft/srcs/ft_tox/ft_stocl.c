/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_stocl.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/30 23:49:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 00:42:47 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_stocl(char *str)
{
	t_clist	*lst;

	lst = NULL;
	if (!str)
		return (NULL);
	while (*str)
		ft_clstadd_end(&lst, ft_clstnew(*str++));
	return (lst);
}
