/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 22:56:18 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:57:21 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <unistd.h>
# include <netdb.h>
# include <dirent.h>
# include <fcntl.h>
# include "libft.h"

# define BUF_SIZE	4096
# define FD_SRV		1
# define FD_CLT		2
# define FD_FREE	0
# define MAX_CHANS	100

typedef struct s_env	t_env;

struct					s_env
{
	char				*name;
	int					my_sock;
	char				buf_read[BUF_SIZE + 1];
	char				buf_write[BUF_SIZE + 1];
	int					r;
	fd_set				fd_read;
	fd_set				fd_read_cpy;
	fd_set				fd_write;
	fd_set				fd_write_cpy;
};

/*
**client.c
*/
int						create_clt(char *addr, int port);
void					check_actions(t_env *e);
void					do_select(t_env *e);
void					run_clt(char **av);
/*
**tools1_client.c
*/
int						my_exit(int sig, char *line);
int						my_error(char c);
void					send_data(t_env *e);
void					receive_data(t_env *e);

#endif
