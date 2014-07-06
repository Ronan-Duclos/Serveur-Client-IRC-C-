/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:42:56 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/02 18:11:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int	index;

	index = 0;
	while (s2 && index < n && s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	while (index < n)
		s1[index] = '\0';
	s1[index] = '\0';
	return (s1);
}
