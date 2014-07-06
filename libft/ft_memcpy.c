/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:33:19 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 11:13:35 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	index;
	char			*a;
	char			*b;

	a = s1;
	b = (char *)s2;
	index = 0;
	while (index < n)
	{
		a[index] = b[index];
		index++;
	}
	return (s1);
}
