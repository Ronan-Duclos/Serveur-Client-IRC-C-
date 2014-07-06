/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:19:49 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:17:40 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * n);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, n);
	return (s);
}
