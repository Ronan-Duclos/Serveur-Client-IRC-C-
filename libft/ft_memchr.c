/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:41:15 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 18:21:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned int	index;

	index = 0;
	s1 = (unsigned char *)s;
	while (s1[index] && s1[index] != '\0' && index < n)
	{
		if (s1[index] == (unsigned char)c)
			return (s1 + index);
		index++;
	}
	return (NULL);
}
