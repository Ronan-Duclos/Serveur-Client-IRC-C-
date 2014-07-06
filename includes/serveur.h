/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 22:56:18 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:58:35 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

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
typedef struct s_fds	t_fds;
typedef struct s_chan	t_chan;
typedef struct s_cb		t_cb;

struct					s_fds
{
	int					type;
	char				*name;
	int					sock;
	void				(*fct_read)();
	void				(*fct_write)();
	char				buf_read[BUF_SIZE + 1];
	char				buf_write[BUF_SIZE + 1];
	char				buf_tmp[BUF_SIZE + 1];
	t_chan				*chan;
	t_fds				*after;
	t_fds				*befor;
};

struct					s_chan
{
	char				*name;
	t_fds				*co;
};

struct					s_env
{
	t_fds				**users;
	t_chan				**chans;
	int					*nb_chans;
	int					maxfd;
	int					max;
	int					r;
	fd_set				fd_read;
	fd_set				fd_read_cpy;
	fd_set				fd_write;
	fd_set				fd_write_cpy;
};

/*
**check_fd.c
*/
void					check_fd(t_env *e);
/*
**client_read.c
*/
void					send_mto_all(t_env *e, int cs, char *line);
void					verify_buf(t_env *e, int cs);
void					client_read(t_env *e, int cs);
/*
**client_write.c
*/
void					client_write(t_env *e, int cs);
/*
**init.c
*/
int						init_serv(int port, t_env *e);
int						get_max_user(void);
void					init_fds(t_env *e);
void					init_chans(t_env *e);
void					init_env(t_env *e, int port);
/*
**make_cmd.c
*/
t_fds					*remove_user(t_chan *to_free, int cs);
void					send_msg(t_env *e, int cs, t_chan *leaved);
void					make_leave(t_env *e, int cs, char *line);
void					make_msg(t_env *e, int cs, char *line);
void					make_cmd(t_env *e, int cs, char *line);
/*
**make_cmd2.c
*/
void					change_name(t_env *e, int cs, char *line);
void					check_name(t_env *e, int cs, char *line);
void					join_chan(t_env *e, int cs, char *line);
void					make_join(t_env *e, int cs, char *line);
void					make_who(t_env *e, int cs, char *line);
/*
**my_hache.c
*/
int						my_hache(char *name);
/*
**serveur.c
*/
void					create_clt(t_env *e);
void					destroy_clt(t_env *e, int sock);
void					make_cpy(t_env *e);
void					run_serv(char *av);
/*
**tools1_serv.c
*/
int						my_error(char c);
char					*less_cmd(char *line);
char					*find_msg(char *msg);
t_fds					*make_lc_chan(t_fds *tail, t_fds *new);
void					free_chan(t_env *e, t_chan *to_free);

#endif
