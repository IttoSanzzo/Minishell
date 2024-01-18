/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_nfreestr.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/30 20:36:47 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/06 19:57:52 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nfreestr(char **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
	return (NULL);
}
