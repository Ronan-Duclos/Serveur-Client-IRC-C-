/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:47:25 by rduclos           #+#    #+#             */
/*   Updated: 2013/12/07 16:36:15 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h>

size_t	ft_strlen(const char *str)
{
	size_t		index;

	index = 0;
	while (str && str[index] != '\0')
		index++;
	return (index);
}
