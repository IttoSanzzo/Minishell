/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/12 20:03:28 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/26 00:12:07 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *body, char *news)
{
	if (body)
		free(body);
	body = ft_strdup(news);
	return (body);
}
