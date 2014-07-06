/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:22:15 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/02 20:10:13 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	m;

	m = n;
	if (*s2 == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		m = n;
		while (s1[i + j] != '\0' && s1[i + j] == s2[j] && n > i + j)
		{
			m--;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
