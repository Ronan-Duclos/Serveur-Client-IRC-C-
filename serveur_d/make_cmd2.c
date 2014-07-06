/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:18:54 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/26 18:53:20 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

void	change_name(t_env *e, int cs, char *line)
{
	char	*tmp;
	char	*tmp2;
	char	*to_resp;
	char	*to_send;

	tmp = ft_strdup(e->users[cs]->name);
	ft_strcpy(e->users[cs]->name, line);
	to_resp = ft_strjoin("You changed your nickname for : \0", line);
	send(cs, to_resp, ft_strlen(to_resp) + 1, 0);
	free(to_resp);
	tmp2 = ft_strjoin(tmp, " change he's nickname for : ");
	free(tmp);
	to_send = ft_strjoin(tmp2, line);
	free(tmp2);
	send_mto_all(e, cs, to_send);
	ft_putendl(to_send);
	free(to_send);
}

void	check_name(t_env *e, int cs, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (line[i] != '\0')
	{
		if (line[i] < 33 || line[i] > 126)
			j = 0;
		i++;
	}
	if (i > 8)
		send(cs, "Nickname limited at 9.\0", 23, 0);
	else if (i == 0)
		send(cs, "Nickname has to be set.\0", 24, 0);
	else if (j == 0)
		send(cs, "Nickname can't take special caractere.\0", 39, 0);
	else
		change_name(e, cs, line);
}

void	join_chan(t_env *e, int cs, char *line)
{
	int		c;
	int		i;
	char	*tmp;

	i = 0;
	c = my_hache(line);
	while (e->chans[c]->name[0] != '\0' &&
			ft_strcmp(e->chans[c]->name, line) != 0)
		c++;
	while (e->nb_chans[i] != -1)
		i++;
	e->nb_chans[i] = c;
	e->chans[c]->name = ft_strcpy(e->chans[c]->name, line);
	e->chans[c]->co = make_lc_chan(e->chans[c]->co, e->users[cs]);
	e->users[cs]->chan = e->chans[c];
	tmp = ft_strjoin("You joined the chanel : ", line);
	send(cs, tmp, ft_strlen(tmp) + 1, 0);
	free(tmp);
	tmp = ft_strjoin(e->users[cs]->name, " joined the chanel.");
	printf("%s\n", tmp);
	send_mto_all(e, cs, tmp);
	free(tmp);
}

void	make_join(t_env *e, int cs, char *line)
{
	if (ft_strlen(line) < 26 && ft_strlen(line) > 2)
	{
		if (e->users[cs]->chan == NULL)
			join_chan(e, cs, line);
		else
			send(cs, "You can't join a chanel when you are already in one.\0", 53, 0);
	}
	else
		send(cs, "Wrong name : 3 characters min, 25 characters max.\0", 50, 0);
}

void	make_who(t_env *e, int cs, char *line)
{
	char	*tmp;
	char	*tmp2;
	t_fds	*users;

	(void)line;
	if (e->users[cs]->chan != NULL)
	{
		users = e->users[cs]->chan->co;
		tmp = ft_strdup(users->name);
		while (users->after != NULL)
		{
			users = users->after;
			tmp2 = ft_strjoin(tmp, "\n");
			free(tmp);
			tmp = ft_strjoin(tmp2, users->name);
			free(tmp2);
		}
		send(cs, tmp, ft_strlen(tmp) + 1, 0);
	}
	else
		send(cs, "You are not in a chanel.\0", 25, 0);
}
