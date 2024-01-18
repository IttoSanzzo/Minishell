/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getcwd.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/16 14:18:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/16 14:18:35 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	ft_getcwd(char **pwd)
{
	int	buftry;

	buftry = 1;
	*pwd = (char *)malloc(BUFFER_PWD * sizeof(char));
	while (!getcwd(*pwd, BUFFER_PWD * buftry) && ++buftry)
	{
		ft_nfreestr(pwd);
		*pwd = (char *)malloc((BUFFER_PWD * buftry) * sizeof(char));
	}
}
