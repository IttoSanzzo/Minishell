/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_stdout_on.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 06:12:55 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 06:13:30 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_stdout_on(void)
{
	if (dup2(STDOUT_FILENO, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}
