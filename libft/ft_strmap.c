/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:31:41 by rduclos           #+#    #+#             */
/*   Updated: 2014/03/27 22:22:12 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char		*str;
	size_t		i;

	i = 0;
	str = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
