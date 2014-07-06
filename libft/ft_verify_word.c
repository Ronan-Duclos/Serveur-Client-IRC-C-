/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:26:35 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:26:36 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_verify_word(char *word, char *verify)
{
	int		i;

	i = 0;
	while (word[i] != '\0' && verify[i] != '\0')
	{
		if (word[i] != verify[i])
			return (1);
		i++;
	}
	if (verify[i] == '\0')
		return (0);
	return (1);
}
