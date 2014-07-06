/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:44:07 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:48:37 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nmatch(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 == '\0')
		return (1);
	if (*s1 == *s2)
		return (ft_nmatch(s1 + 1, s2 + 1));
	if (*s2 == '*' && *s1 != '\0')
		return (ft_nmatch(s1 + 1, s2) + ft_nmatch(s1, s2 + 1));
	if (*s2 == '*')
		return (ft_nmatch(s1, s2 + 1));
	return (0);
}
