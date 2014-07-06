/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hache.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:22:07 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:52:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		my_hache(char *name)
{
	int		i;
	int		j;
	int		total;

	i = 0;
	j = 1;
	total = 0;
	while (name[i] != '\0')
	{
		total = total + ((int)name[i] * j);
		i++;
		j *= 2;
	}
	return (total % MAX_CHANS);
}
