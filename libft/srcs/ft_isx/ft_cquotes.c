/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_cquotes.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 16:42:19 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/14 15:19:48 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	cquotes(char *line, int *open, int i, int *bl)
{
	if (*open != 1 && line[i] == '\\' && !*bl)
	{
		*bl = 1;
		return (3);
	}
	else if (*bl)
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

int	ft_cquotes(char *s)
{
	int	open;
	int	bl;
	int	i;

	open = 0;
	bl = 0;
	i = -1;
	if (!s)
		return (0);
	while (s[++i])
	{
		if (cquotes(s, &open, i, &bl) == 3)
			continue ;
		bl = 0;
	}
	return (open);
}
