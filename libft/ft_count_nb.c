/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 11:39:12 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 19:48:38 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_nb(int c)
{
	int		i;

	i = 0;
	if (c < 0)
	{
		i++;
		c *= -1;
	}
	while ((c = c / 10) > 0)
		i++;
	return (i + 1);
}