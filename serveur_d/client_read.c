/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 20:06:47 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:44:26 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "serveur.h"

void	send_mto_all(t_env *e, int cs, char *line)
{
	int		i;
	char	*tmp2;
	char	*tosend;
	t_fds	*tmp;

	i = 0;
	if (e->users[cs]->chan != NULL)
	{
		tmp = e->users[cs]->chan->co;
		tmp2 = ft_strjoin(e->users[cs]->name, " : ");
		tosend = ft_strjoin(tmp2, line);
		free(tmp2);
		while (tmp != NULL)
		{
			if (tmp->sock != cs)
				send(tmp->sock, tosend, ft_strlen(tosend) + 1, 0);
			tmp = tmp->after;
		}
		free(tosend);
	}
}

void	verify_buf(t_env *e, int cs)
{
	if (e->users[cs]->buf_tmp[0] == '\0')
		ft_strcpy(e->users[cs]->buf_tmp, e->users[cs]->buf_read);
	else
		ft_strcat(e->users[cs]->buf_tmp, e->users[cs]->buf_read);
	if (ft_strchr(e->users[cs]->buf_tmp, '\n') != NULL)
	{
		ft_strcpy(e->users[cs]->buf_read, e->users[cs]->buf_tmp);
		e->users[cs]->buf_tmp[0] = '\0';
	}
}

void	client_read(t_env *e, int cs)
{
	int		r;

	r = recv(cs, e->users[cs]->buf_read, BUF_SIZE, 0);
	if (r <= 0)
	{
		close(cs);
		destroy_clt(e, cs);
	}
	else
	{
		verify_buf(e, cs);
		if (ft_strchr(e->users[cs]->buf_read, '\n') != NULL)
		{
			r = ft_strlen(e->users[cs]->buf_read);
			e->users[cs]->buf_read[r - 1] = '\0';
			if (e->users[cs]->buf_read[0] == '/')
				make_cmd(e, cs, e->users[cs]->buf_read);
			else
				send_mto_all(e, cs, e->users[cs]->buf_read);
		}
	}
}
