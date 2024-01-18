/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_newfile.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 11:15:00 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 11:19:43 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_newfile(const char *name)
{
	int	perm;
	int	fd;

	perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, perm);
	if (fd == -1)
		perror("ft_readline: newfile failure.");
	close(fd);
}
