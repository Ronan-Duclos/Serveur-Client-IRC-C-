#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caupetit <caupetit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/12 18:06:35 by caupetit          #+#    #+#              #
#    Updated: 2014/05/25 17:04:05 by rduclos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SERV_NAME = serveur
CLT_NAME = client
FLAGS = -Wall -Wextra -Werror
LIB = -L libft/ -lft
INCLUDES = -I includes/ -I libft
CLT_H = $(INCLUDES)client.h
SERV_H = $(INCLUDES)serveur.h

CC = llvm-gcc

DIROBJ = obj/
DIRSRV = serveur_d/
DIRCLT = client_d/

SERV_SRC =	serveur.c check_fd.c client_write.c client_read.c init.c  \
			make_cmd.c my_hache.c make_cmd2.c tools1_serv.c

CLT_SRC =	client.c tools1_client.c

SERV_OBJ = $(SERV_SRC:%.c=$(DIROBJ)%.o)
CLT_OBJ = $(CLT_SRC:%.c=$(DIROBJ)%.o)

all: init $(CLT_NAME) $(SERV_NAME)

init:
	@mkdir obj
	@make -s -C libft/
	@tput init


$(SERV_NAME): $(SERV_OBJ)
	@echo "==> Compiling $(SERV_NAME)"
	@$(CC) $(FLAGS) -o $@ $(SERV_OBJ) $(INCLUDES) $(LIB)
	@sleep .5
	@tput cuu1
	@echo "\033[2K\t\033[1;36m$(SERV_NAME)\t\t\033[0;32m[Ready]\033[0m"

$(CLT_NAME): $(CLT_OBJ)
	@echo "==> Compiling $(CLT_NAME) : "
	@$(CC) $(FLAGS) -o $@ $(CLT_OBJ) $(INCLUDES) $(LIB)
	@sleep .5
	@tput cuu1
	@echo "\033[2K\t\033[1;36m$(CLT_NAME)\t\t\033[0;32m[Ready]\033[0m"

$(DIROBJ)%.o: $(DIRSRV)%.c
	@echo "--> Compiling $<"
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

$(DIROBJ)%.o: $(DIRCLT)%.c
	@echo "--> Compiling $<"
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

clean:
	@rm -rf obj
	@make -C libft $@
	@rm -f $(SERV_OBJ)
	@echo "[$(SERV_NAME)]--> Objects removed"
	@rm -f $(CLT_OBJ)
	@echo "[$(CLT_NAME)] --> Objects removed"

fclean: clean
	@make -C libft $@
	@rm -f $(CLT_NAME)
	@echo "[$(SERV_NAME)]--> Program removed"
	@rm -f $(SERV_NAME)
	@echo "[$(CLT_NAME)] --> Program removed"

re: fclean all
