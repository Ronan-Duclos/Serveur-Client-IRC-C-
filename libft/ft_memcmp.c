/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:48:21 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 11:13:03 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1a;
	unsigned char	*s2a;
	unsigned int	index;

	index = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	while (index < n)
	{
		if (s1a[index] != s2a[index])
			return (s1a[index] - s2a[index]);
		index++;
	}
	return (0);
}
