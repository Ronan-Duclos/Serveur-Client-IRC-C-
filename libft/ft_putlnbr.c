/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:44:59 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:45:29 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putlnbr(long n)
{
	long	div;
	int		index;

	index = 0;
	div = 1;
	if (n < 0)
	{
		index = ft_putchar('-');
		n = n * -1;
	}
	while ((n / div) >= 10)
		div = div * 10;
	while (div > 0)
	{
		index += ft_putchar((n / div) % 10 + 48);
		div = div / 10;
	}
	return (index);
}
