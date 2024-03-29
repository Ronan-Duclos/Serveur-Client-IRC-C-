/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:43:06 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:44:46 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	if (ft_nmatch(s1, s2) > 0)
		return (1);
	return (0);
}
