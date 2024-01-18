/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 19:37:34 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 16:08:32 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstnew(char val)
{
	t_clist	*newlst;

	newlst = (t_clist *)malloc(sizeof(t_clist));
	if (!newlst)
		return (NULL);
	newlst->val = val;
	newlst->next = NULL;
	return (newlst);
}
