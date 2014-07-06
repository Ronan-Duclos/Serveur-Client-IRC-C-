/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char_befor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:24:00 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:44:00 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_char_befor(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str != NULL && str[i] != c && str[i] != '\0')
		i++;
	return (i);
}
