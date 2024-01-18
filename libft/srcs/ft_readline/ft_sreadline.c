/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_sreadline.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/08 09:13:14 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/08 03:50:06 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sreadline(char *prompt)
{
	char	*line;
	char	buffer[1];

	ft_putstr(prompt);
	buffer[0] = 0;
	if (read(0, buffer, 1) == 0)
		return (NULL);
	line = (char *)ft_calloc(2, sizeof(char));
	if (!line)
		return (NULL);
	while (*buffer != '\n')
	{
		line = ft_sujoin(&line, buffer);
		while (read(0, buffer, 1) == 0)
			buffer[0] = 0;
	}
	return (line);
}
