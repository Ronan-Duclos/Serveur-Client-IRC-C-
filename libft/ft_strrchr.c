/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:47:21 by rduclos           #+#    #+#             */
/*   Updated: 2013/11/29 14:01:47 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrchr(const char *s, int c)
{
	char		*str;

	str = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			str = (char *)s;
		s++;
	}
	if (c == '\0')
		str = (char *)s;
	return (str);
}
