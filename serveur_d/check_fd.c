/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 20:06:02 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:33:57 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	check_fd(t_env *e)
{
	int		i;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		if (e->users[i]->type != FD_FREE)
		{
			if (FD_ISSET(e->users[i]->sock, &e->fd_read_cpy) != 0)
				e->users[i]->fct_read(e, e->users[i]->sock);
			if (FD_ISSET(e->users[i]->sock, &e->fd_write_cpy) != 0)
				e->users[i]->fct_write(e, e->users[i]->sock);
			if (FD_ISSET(e->users[i]->sock, &e->fd_read_cpy) != 0 ||
				FD_ISSET(e->users[i]->sock, &e->fd_write_cpy) != 0)
				e->r--;
		}
		i++;
	}
}
