/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:39:34 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/22 14:58:43 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putstr(const char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
		index++;
	write(1, str, index);
	return (index);
}
