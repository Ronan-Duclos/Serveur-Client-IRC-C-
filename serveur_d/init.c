/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 19:08:44 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:45:40 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		init_serv(int port, t_env *e)
{
	int					sock;
	struct protoent		*prt;
	struct sockaddr_in	srv;

	srv.sin_family = AF_INET;
	srv.sin_port = htons(port);
	srv.sin_addr.s_addr = htonl(INADDR_ANY);
	prt = getprotobyname("TCP");
	if (prt == 0)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, prt->p_proto)) == -1)
		return (my_error('s'));
	if (bind(sock, (const struct sockaddr *)&srv, sizeof(srv)) == -1)
		return (my_error('b'));
	if (listen(sock, 42) == -1)
		return (my_error('l'));
	e->max = sock;
	return (sock);
}

int		get_max_user(void)
{
	struct rlimit	rlp;

	if (getrlimit(RLIMIT_NOFILE, &rlp) != 0)
		exit(0);
	return (rlp.rlim_cur);
}

void	init_fds(t_env *e)
{
	int	i;

	i = 0;
	e->users = (t_fds **)malloc(sizeof(t_fds *) * (e->maxfd));
	while (i < e->maxfd)
	{
		e->users[i] = (t_fds *)malloc(sizeof(t_fds));
		e->users[i]->type = FD_FREE;
		e->users[i]->name = (char *)malloc(sizeof(char) * (10));
		e->users[i]->name = ft_strcpy(e->users[i]->name, "Bob\0");
		e->users[i]->chan = NULL;
		e->users[i]->buf_tmp[0] = '\0';
		e->users[i]->after = NULL;
		e->users[i]->befor = NULL;
		e->users[i]->fct_read = client_read;
		e->users[i]->fct_write = client_write;
		i++;
	}
}

void	init_chans(t_env *e)
{
	int	i;

	i = 0;
	e->chans = (t_chan **)malloc(sizeof(t_chan *) * MAX_CHANS);
	e->nb_chans = (int *)malloc(sizeof(int) * (MAX_CHANS + 1));
	while (i < MAX_CHANS)
	{
		e->chans[i] = (t_chan *)malloc(sizeof(t_chan));
		e->chans[i]->name = (char *)malloc(sizeof(char) * 26);
		e->chans[i]->name = ft_strcpy(e->chans[i]->name, "\0");
		e->chans[i]->co = NULL;
		e->nb_chans[i] = -1;
		i++;
	}
}

void	init_env(t_env *e, int port)
{
	e->maxfd = get_max_user();
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	init_fds(e);
	init_chans(e);
	e->users[0]->sock = init_serv(port, e);
	FD_SET(e->users[0]->sock, &e->fd_read);
	FD_SET(e->users[0]->sock, &e->fd_write);
	e->users[0]->type = FD_SRV;
	e->users[0]->fct_read = create_clt;
	e->users[0]->fct_write = client_write;
}
