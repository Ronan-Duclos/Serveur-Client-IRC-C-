/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:02:15 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:24:42 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	len1;
	int				len2;

	len1 = 0;
	len2 = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (len1 < ft_strlen(s1) + 1)
	{
		if (s2[len2] == '\0')
			return ((char *)s1 + (len1 - len2));
		else if (s1[len1] == s2[len2])
		{
			len2++;
		}
		else
		{
			len2 = 0;
		}
		len1++;
	}
	return (NULL);
}
