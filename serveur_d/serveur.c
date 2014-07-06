/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:12:01 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/29 18:26:46 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	create_clt(t_env *e)
{
	int						cs;
	unsigned int			len;
	struct sockaddr_in		clt;

	if ((cs = accept(e->users[0]->sock, (struct sockaddr *)&clt, &len)) == -1)
		return ;
	e->users[cs]->type = FD_CLT;
	e->users[cs]->sock = cs;
	e->users[cs]->chan = NULL;
	e->users[cs]->after = NULL;
	e->users[cs]->befor = NULL;
	FD_SET(cs, &e->fd_read);
	FD_SET(cs, &e->fd_write);
	if (e->max < cs)
		e->max = cs;
	printf("Client connected : %d\n", cs);
}

void	destroy_clt(t_env *e, int sock)
{
	if (e->users[sock]->chan != NULL)
		make_leave(e, sock, "\0");
	e->users[sock]->type = FD_FREE;
	e->users[sock]->sock = 0;
	e->users[sock]->chan = NULL;
	ft_strcpy(e->users[sock]->name, "Bob\0");
	e->users[sock]->buf_read[0] = '\0';
	e->users[sock]->buf_write[0] = '\0';
	e->users[sock]->buf_tmp[0] = '\0';
	e->users[sock]->after = NULL;
	e->users[sock]->befor = NULL;
	FD_CLR(sock, &e->fd_read);
	FD_CLR(sock, &e->fd_write);
	printf("Client deconnected : %d\n", sock);
}

void	make_cpy(t_env *e)
{
	FD_ZERO(&e->fd_read_cpy);
	FD_ZERO(&e->fd_write_cpy);
	FD_COPY(&e->fd_read, &e->fd_read_cpy);
	FD_COPY(&e->fd_write, &e->fd_write_cpy);
}

void	run_serv(char *av)
{
	t_env		e;

	init_env(&e, atoi(av));
	printf("Init : OK\n");
	while (1)
	{
		make_cpy(&e);
		e.r = select(e.max + 1, &e.fd_read_cpy, &e.fd_write_cpy, NULL, NULL);
		check_fd(&e);
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		printf("Usage de %s : ./%s <port>", av[0], av[0]);
	else
		run_serv(av[1]);
	return (0);
}
