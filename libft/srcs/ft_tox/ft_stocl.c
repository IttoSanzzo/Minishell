/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:47:02 by marcosv2          #+#    #+#             */
/*   Updated: 2024/01/19 21:47:03 by marcosv2         ###   ########.fr       */
/*                                                                            */
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
