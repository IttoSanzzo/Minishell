/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_squotes.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/10 02:33:36 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/12 01:16:32 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_squotes(char *line, int *open, int i)
{
	if (i > 0 && line[i - 1] == '\\')
		return (0);
	else if (line[i] == '\"' || line[i] == '\'')
	{
		if (*open == 0 && line[i] == '\"')
			*open = 2;
		else if (*open == 0 && line[i] == '\'')
			*open = 1;
		else if (*open == 2 && line[i] == '\"')
			*open = 0;
		else if (*open == 1 && line[i] == '\'')
			*open = 0;
		return (1);
	}
	return (0);
}
