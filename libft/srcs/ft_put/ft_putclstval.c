/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_putclstval.c                                    :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 01:23:37 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/03 05:02:42 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

// Writes the very first char of a clist in the stdout, mantaining it.
void	ft_putclstval(t_clist *lst)
{
	if (!lst)
		return ;
	ft_putchar(lst->val);
}
