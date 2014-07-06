/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:05:23 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/02 18:52:54 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*in_read(char *buf, char *str)
{
	char	*tmp;

	if (str != NULL)
	{
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	else
		str = ft_strdup(buf);
	return (str);
}

static void		make_line(char **line, char **str, char *tmp)
{
	size_t	i;

	i = ft_count_char_befor(*str, '\n');
	*line = (char *)malloc(sizeof(char) * (i + 1));
	*line = ft_strncpy(*line, *str, i);
	if (tmp[0] != '\0' && tmp[1] != '\0')
	{
		free(*str);
		*str = ft_strdup(tmp + 1);
	}
	else
	{
		free(*str);
		*str = NULL;
	}
}

static void		make_end(char **line, char **str)
{
	size_t	i;

	i = 0;
	while (*str && (*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
			(*str)[i] = '\0';
		else
			i++;
	}
	if (i > 0)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
}

int				get_next_line(int const fd, char **line)
{
	static char	*str;
	char		*buf;
	char		*tmp;
	int			ret;

	buf = ft_strnew(GET_SIZE);
	while (ft_strchr(buf, '\n') == NULL && (ret = read(fd, buf, GET_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = in_read(buf, str);
	}
	if (ret == -1)
		return (-1);
	if ((tmp = ft_strchr(str, '\n')) != NULL)
		make_line(line, &str, tmp);
	else if (ret == 0 && str != NULL && str[0] != '\0')
		make_end(line, &str);
	else
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
}
