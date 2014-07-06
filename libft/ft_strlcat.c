/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:23:34 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:21:59 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;
	size_t		j;

	len = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len);
}
