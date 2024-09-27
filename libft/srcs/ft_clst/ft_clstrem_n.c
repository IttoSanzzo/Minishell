/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:29 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:13:30 by marcosv2         ###   ########.fr       */
/*                                                                            */
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
