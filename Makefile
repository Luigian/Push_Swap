# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 19:27:37 by lusanche          #+#    #+#              #
#    Updated: 2020/01/18 11:06:41 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = checker_main.c operations.c
OBJ = $(SRC:.c=.o)
LIBFT = ulibft/
LB_H = ulibft/libft.h

$(NAME):
	@make -C $(LIBFT) fclean && make -C $(LIBFT)
	@$(CC) $(FLAGS) -I $(LB_H) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -I $(LB_H) -L $(LIBFT) -lft
	@echo "[INFO] [$(NAME)] created"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) fclean 
	@echo "[INFO] Checker Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] [$(NAME)] removed"

re: fclean all
