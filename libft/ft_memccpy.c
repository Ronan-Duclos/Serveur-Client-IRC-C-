/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:33:19 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 14:14:24 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*a;
	unsigned char	*b;

	a = s1;
	b = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		a[index] = b[index];
		if (a[index] == (unsigned char)c)
			return (s1 + index + 1);
		index++;
	}
	return ((void *)0);
}
