/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstadd_n.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 00:53:05 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstadd_n(t_clist **lst, t_clist *new, int n)
{
	int		i;
	t_clist	*temp;

	if (!new || n < 0)
		return (NULL);
	if (!*lst || n == 0)
		return (ft_clstadd_bgn(lst, new));
	i = 0;
	temp = *lst;
	while (temp->next && ++i < n)
		temp = temp->next;
	if (temp->next)
		new->next = temp->next;
	temp->next = new;
	return (*lst);
}
