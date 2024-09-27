/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:27:17 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/19 11:39:08 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_ext(char *file, char *ext)
{
	int	i;
	int	len;

	if (!file || !ext)
		return (0);
	len = ft_strlen(ext) + 1;
	i = ft_strlen(file);
	while (file[--i])
		if (file[i] == '.' && !ft_strncmp((char *)(file + i + 1), ext, len))
			return (1);
	return (0);
}
