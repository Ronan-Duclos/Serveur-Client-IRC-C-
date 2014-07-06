/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:43:27 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:21:16 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen((char *)s);
	while (s && index < len + 1)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index++;
	}
	return (NULL);
}
