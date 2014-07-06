/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 18:11:48 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/29 18:37:03 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		create_clt(char *addr, int port)
{
	int					sock;
	struct protoent		*prt;
	struct sockaddr_in	clt;

	clt.sin_family = AF_INET;
	clt.sin_port = htons(port);
	clt.sin_addr.s_addr = inet_addr(addr);
	prt = getprotobyname("TCP");
	if (prt == 0)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, prt->p_proto)) == -1)
		return (my_error('s'));
	if (connect(sock, (const struct sockaddr *)&clt, sizeof(clt)) == -1)
		return (my_error('b'));
	printf("Client OK\n");
	return (sock);
}

void	check_actions(t_env *e)
{
	while (e->r != 0)
	{
		if (FD_ISSET(0, &e->fd_read_cpy))
		{
			e->r--;
			send_data(e);
		}
		if (FD_ISSET(0, &e->fd_write_cpy))
			e->r--;
		if (FD_ISSET(e->my_sock, &e->fd_read_cpy))
		{
			e->r--;
			receive_data(e);
		}
		if (FD_ISSET(e->my_sock, &e->fd_write_cpy))
			e->r--;
	}
}

void	do_select(t_env *e)
{
	fd_set	*read;
	fd_set	*write;

	read = &e->fd_read_cpy;
	write = &e->fd_write_cpy;
	e->r = select(e->my_sock + 1, read, write, NULL, NULL);
}

void	init_clt(t_env *e)
{
		FD_ZERO(&e->fd_write);
		FD_ZERO(&e->fd_read);
		FD_ZERO(&e->fd_write_cpy);
		FD_ZERO(&e->fd_read_cpy);
		FD_SET(0, &e->fd_read);
		FD_SET(e->my_sock, &e->fd_read);
}

void	run_clt(char **av)
{
	t_env	e;

	if ((e.my_sock = create_clt(av[1], ft_atoi(av[2]))) != -1)
	{
		init_clt(&e);
		while (my_exit(1, NULL) != 1)
		{
			FD_COPY(&e.fd_read, &e.fd_read_cpy);
			FD_COPY(&e.fd_write, &e.fd_write_cpy);
			do_select(&e);
			check_actions(&e);
			FD_ZERO(&e.fd_read_cpy);
			FD_ZERO(&e.fd_write_cpy);
		}
		close(e.my_sock);
	}
}

int		main(int ac, char **av)
{
	if (ac != 3)
		printf("Usage de %s : <addresse> <port>.\n", av[0]);
	else
		run_clt(av);
	return (0);
}
