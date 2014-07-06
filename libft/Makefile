#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 11:38:09 by rduclos           #+#    #+#              #
#    Updated: 2014/05/02 18:58:06 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = 	ft_putchar.c ft_putstr.c ft_putnbr.c ft_strcat.c ft_strchr.c \
		ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c \
		ft_strncpy.c ft_strrchr.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memalloc.c ft_memdel.c ft_striter.c ft_striteri.c \
		ft_count_char_befor.c ft_match.c ft_strclr.c ft_strnew.c ft_strdel.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_count_nb.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putendl.c \
		ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstnew.c \
		ft_putnbr_fd.c ft_nmatch.c ft_putlnbr.c ft_putpnbr.c \
		ft_realloc_str.c ft_reverse_str.c ft_lstmap.c get_next_line.c \
		ft_verify_word.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJ) end
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

libft:
	@echo -n 'Libft : '

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -I .
	@echo -n '.'

end:
	@echo ''

clean:
	@rm -f $(OBJ)
	@echo '[libft]  -->  clean'

fclean: clean
	@rm -f $(NAME)
	@echo '[libft]  -->  fclean'

re: fclean all
