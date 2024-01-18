/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_clstrem_n.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/24 21:36:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 00:53:17 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_n(t_clist **lst, int n)
{
	int		i;
	t_clist	*temp;

	if (n < 0)
		return (NULL);
	if (!*lst || n == 0)
		return (ft_clstrem_bgn(lst));
	i = 0;
	temp = *lst;
	while (temp->next && ++i < n)
		temp = temp->next;
	ft_clstrem_bgn(&temp->next);
	return (*lst);
}
