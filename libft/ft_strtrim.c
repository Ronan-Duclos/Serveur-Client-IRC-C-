/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:50:48 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:22:47 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_cut_al(char a)
{
	if (a == ' ' || a == '\n' || a == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_cut_al(s[i]) == 1 && i < j)
		i++;
	while (ft_cut_al(s[j - 1]) == 1 && j != 0)
		j--;
	str = ft_strsub(s, i, j - i);
	return (str);
}
