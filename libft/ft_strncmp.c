/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:37:31 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/24 16:27:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] != '\0' && s2[index] != '\0' && index < n)
	{
		if (s1[index] != s2[index])
			return ((char)s1[index] - (char)s2[index]);
		index++;
	}
	if (index < n && s1[index] != s2[index])
		return ((char)s1[index] - (char)s2[index]);
	return (0);
}
