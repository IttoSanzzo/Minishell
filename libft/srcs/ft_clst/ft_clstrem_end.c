/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:35 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:13:36 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_end(t_clist **lst)
{
	t_clist	*last;

	if (!*lst)
		return (NULL);
	last = *lst;
	if (!last->next)
		return (ft_nfreeclst(lst));
	while (last->next->next)
		last = last->next;
	ft_nfreeclst(&last->next);
	return (*lst);
}
