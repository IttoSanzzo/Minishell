/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 09:35:58 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 09:53:26 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ftos(char *file, char **output)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	*output = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		ft_freejoin(output, &line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
