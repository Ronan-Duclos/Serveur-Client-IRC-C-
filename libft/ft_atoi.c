/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:03:16 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:14:59 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	int		total;
	int		neg;
	size_t	i;

	total = 0;
	neg = 1;
	i = 0;
	while (str && !ft_isalnum(str[i]) && !(str[i] == '-'))
		if (str[i++] == 0)
			return (0);
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while ((str && str[i] >= '0') && (str[i] <= '9'))
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	return (neg * total);
}
