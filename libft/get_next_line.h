/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:08:30 by rduclos           #+#    #+#             */
/*   Updated: 2014/05/02 18:50:52 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define GET_SIZE 1024
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int	get_next_line(int const fd, char **line);

#endif
