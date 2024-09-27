/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstrem_bgn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:13:40 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 20:13:45 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_clist	*ft_clstrem_bgn(t_clist **lst)
{
	t_clist	*temp;

	if (!*lst)
		return (NULL);
	temp = *lst;
	*lst = temp->next;
	free(temp);
	return (*lst);
}
