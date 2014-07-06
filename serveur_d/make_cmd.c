/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:18:22 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:47:10 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

t_fds	*remove_user(t_chan *to_free, int cs)
{
	t_fds	*tmp;
	t_fds	*after;
	t_fds	*befor;

	tmp = to_free->co;
	while (tmp->sock != cs)
		tmp = tmp->after;
	after = tmp->after;
	befor = tmp->befor;
	if (after != NULL)
		after->befor = befor;
	if (befor != NULL)
		befor->after = after;
	tmp->befor = NULL;
	tmp->after = NULL;
	if (befor == NULL)
		tmp = after;
	else
		tmp = befor;
	while (tmp->befor != NULL)
		tmp = tmp->befor;
	return (tmp);
}

void	send_msg(t_env *e, int cs, t_chan *leaved)
{
	char	*chan;
	char	*tmp;

	chan = leaved->name;
	tmp = ft_strjoin("You leaved the chan : ", chan);
	send(cs, tmp, ft_strlen(tmp) + 1, 0);
	free(tmp);
	tmp = ft_strjoin(e->users[cs]->name, " leaved the chan.");
	send_mto_all(e, cs, tmp);
	printf("%s\n", tmp);
	free(tmp);
}

void	make_leave(t_env *e, int cs, char *line)
{
	t_chan	*tmp;

	(void)line;
	tmp = e->users[cs]->chan;
	if (tmp != NULL)
	{
		send_msg(e, cs, tmp);
		if (tmp->co->after == NULL)
			free_chan(e, tmp);
		else
			tmp->co = remove_user(tmp, cs);
		e->users[cs]->chan = NULL;
	}
	else
		send(cs, "You can't leave what you didn't joined\0", 39, 0);
}

void	make_msg(t_env *e, int cs, char *line)
{
	char	*msg;
	char	*tmp;
	char	*tosend;
	int		i;

	i = 0;
	msg = find_msg(line);
	while (i < e->maxfd)
	{
		if (e->users[i]->type == FD_CLT &&
			ft_strcmp(line, e->users[i]->name) == 0)
		{
			tmp = ft_strjoin(e->users[cs]->name, " send to you : ");
			tosend = ft_strjoin(tmp, msg);
			free(tmp);
			send(e->users[i]->sock, tosend, ft_strlen(tosend) + 1, 0);
			free(tosend);
		}
		i++;
	}
}

void	make_cmd(t_env *e, int cs, char *line)
{
	char	*arg;

	arg = less_cmd(line);
	if (ft_verify_word(line, "/nick") == 0)
		check_name(e, cs, arg);
	else if (ft_verify_word(line, "/join") == 0)
		make_join(e, cs, arg);
	else if (ft_strcmp(line, "/leave") == 0)
		make_leave(e, cs, arg);
	else if (ft_strcmp(line, "/who") == 0)
		make_who(e, cs, arg);
	else if (ft_verify_word(line, "/msg") == 0)
		make_msg(e, cs, arg);
	else
		send(cs, "Wrong command.\0", 15, 0);
}
