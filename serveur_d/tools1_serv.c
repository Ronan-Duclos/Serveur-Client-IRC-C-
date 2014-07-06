/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1_serv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:09:04 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:53:42 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"

int		my_error(char c)
{
	ft_putstr("Serveur : ");
	if (c == 'a')
		ft_putendl("accept failed, client failure.");
	else if (c == 'b')
	{
		ft_putendl("bind failed, wrong Port.");
		return (-1);
	}
	else if (c == 's')
	{
		ft_putendl("soket failed, wrong Addresse.");
		return (-1);
	}
	else if (c == 'l')
	{
		ft_putendl("listen failed, problems network.");
		return (-1);
	}
	return (-1);
}

char	*less_cmd(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (line + i);
}

char	*find_msg(char *msg)
{
	int		i;

	i = 0;
	while (msg[i] != '\0' && msg[i] != ' ')
		i++;
	if (msg[i] == ' ' && msg[i + 1] != '\0')
		msg[i] = '\0';
	return (msg + i + 1);
}

t_fds	*make_lc_chan(t_fds *tail, t_fds *new)
{
	if (tail == NULL)
		tail = new;
	else
	{
		tail->befor = new;
		new->after = tail;
		tail = new;
	}
	return (tail);
}

void	free_chan(t_env *e, t_chan *to_free)
{
	int		c;
	int		i;

	i = 0;
	c = my_hache(to_free->name);
	while (e->nb_chans[i] != c)
		i++;
	e->nb_chans[i] = -1;
	to_free->name[0] = '\0';
	to_free->co = NULL;
}
