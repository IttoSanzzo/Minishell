/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_cltos.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/30 23:39:51 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/30 23:57:39 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cltos(t_clist *lst)
{
	t_clist	*temp;
	char	*str;
	char	*ret;

	if (!lst)
		return (NULL);
	str = (char *)ft_calloc(ft_clstlen(lst) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	temp = lst;
	while (temp)
	{
		*str++ = temp->val;
		temp = temp->next;
	}
	return (ret);
}
