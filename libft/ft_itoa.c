/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:20:40 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:51:33 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa2(int nb)
{
	char	*result;
	int		i;
	int		j;
	int		neg;

	i = 0;
	j = 1;
	neg = 1;
	result = malloc(12);
	if (nb < 0)
	{
		neg = -1;
		nb *= (-1);
	}
	while ((nb / j) != 0)
	{
		result[i] = '0' + ((nb / j) % 10);
		j *= 10;
		i++;
	}
	if (neg == -1)
		result[i++] = '-';
	result[i] = '\0';
	return (result = ft_reverse_str(result));
}

char			*ft_itoa(int nb)
{
	char	*result;

	if (nb == 0)
	{
		result = malloc(2);
		result = "0";
		return (result);
	}
	else if (nb == -2147483648)
	{
		result = malloc(12);
		result = "-2147483648\0";
		return (result);
	}
	else if (nb == 2147483647)
	{
		result = malloc(12);
		result = "2147483647\0";
		return (result);
	}
	else
		result = ft_itoa2(nb);
	return (result);
}
