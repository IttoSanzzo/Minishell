/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/10/27 20:21:57 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/10/27 20:27:10 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int nb)
{
	int	count;

	if (nb == 0)
		return (1);
	count = 0;
	while (nb > 0 && ++count)
		nb /= 10;
	return (count);
}

char	*ft_itoa(int n)
{
	int		n_size;
	int		is_negative;
	int		overflow;
	char	*string;

	overflow = 0;
	is_negative = 0;
	if (n == -2147483648 && ++overflow)
		n++;
	if (n < 0 && ++is_negative)
		n *= -1;
	n_size = ft_countdigits(n) + is_negative;
	string = (char *)malloc(sizeof(char) * (n_size) + 1);
	if (!string)
		return (NULL);
	if (is_negative)
		string[0] = '-';
	string[n_size] = '\0';
	while (n_size-- > (0 + is_negative))
	{
		string[n_size] = ((n % 10) + '0' + overflow);
		overflow = 0;
		n /= 10;
	}
	return (string);
}
