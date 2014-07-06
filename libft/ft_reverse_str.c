/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:25:15 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:48:25 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_reverse_str(char *str)
{
	size_t	i;
	size_t	j;
	char	*reverse;

	i = 0;
	j = ft_strlen(str) - 1;
	reverse = (char *)malloc(sizeof(char) * j + 1);
	while (i < ft_strlen(str))
	{
		reverse[i] = str[j];
		i++;
		j--;
	}
	reverse[i] = '\0';
	str = ft_strcpy(str, reverse);
	free(reverse);
	return (str);
}
