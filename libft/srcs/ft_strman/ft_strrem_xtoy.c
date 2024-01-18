/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strrem_xtoy.c                                   :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2024/01/17 00:23:15 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/17 01:41:33 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	strrem_xtoy_len(char *s, int x, int y)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (s[++i] && i < x)
		len++;
	while (s[i] && i < y)
		i++;
	while (s[++i])
		len++;
	return (len);
}

char	*ft_strrem_xtoy(char **s, int x, int y)
{
	int		len;
	int		i;
	int		p;
	char	*trim;

	if (!s || !*s || x < 0 || y < 0 || x > y)
		return (NULL);
	len = strrem_xtoy_len(*s, x, y);
	trim = (char *)ft_calloc(len + 1, sizeof(char));
	p = -1;
	i = -1;
	while (s[0][++i] && i < x)
		trim[++p] = s[0][i];
	while (s[0][i] && i < y)
		i++;
	while (s[0][++i])
		trim[++p] = s[0][i];
	ft_nfreestr(s);
	*s = trim;
	return (trim);
}
