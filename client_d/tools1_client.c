/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 16:04:27 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/25 16:56:41 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		my_exit(int sig, char *line)
{
	static int	i;

	if (sig == 0 && line != NULL)
	{
		if (ft_strcmp(line, "/quit\0") == 0)
			i = 1;
	}
	return (i);
}

int		my_error(char c)
{
	ft_putstr("Serveur : \0");
	if (c == 'a')
		ft_putendl("accept failed, client failure.\0");
	else if (c == 'b')
	{
		ft_putendl("Connect failed, wrong Port.\0");
		return (-1);
	}
	else if (c == 's')
	{
		ft_putendl("soket failed, wrong Addresse.\0");
		return (-1);
	}
	return (-1);
}

void	send_data(t_env *e)
{
	char	*line;
	char	*tmp;

	get_next_line(0, &line);
	my_exit(0, line);
	tmp = ft_strjoin(line, "\n");
	send(e->my_sock, tmp, ft_strlen(tmp) + 1, 0);
	free(tmp);
	free(line);
}

void	receive_data(t_env *e)
{
	int		r;

	r = recv(e->my_sock, e->buf_read, BUF_SIZE, 0);
	e->buf_read[r] = '\0';
	ft_putendl(e->buf_read);
}
