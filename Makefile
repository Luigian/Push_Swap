# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 19:27:37 by lusanche          #+#    #+#              #
#    Updated: 2020/01/22 10:29:13 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = checker
NAME_2 = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_1 = checker_main.c operations.c
SRC_2 = push_main.c operations.c
OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)
LIBFT = ulibft/
LB_H = ulibft/libft.h

$(NAME_2):
	@make -C $(LIBFT) fclean && make -C $(LIBFT)
	@$(CC) $(FLAGS) -I $(LB_H) -c $(SRC_1)
	@$(CC) -o $(NAME_1) $(OBJ_1) -I $(LB_H) -L $(LIBFT) -lft
	@echo "[INFO] [$(NAME_1)] created"
	@rm -f $(OBJ_1)
	@echo "[INFO] Checker Objects removed"
	@$(CC) $(FLAGS) -I $(LB_H) -c $(SRC_2)
	@$(CC) -o $(NAME_2) $(OBJ_2) -I $(LB_H) -L $(LIBFT) -lft
	@echo "[INFO] [$(NAME_2)] created"

.PHONY: all, clean, fclean, re

all: $(NAME_2)

clean:
	@rm -f $(OBJ_2)
	@make -C $(LIBFT) fclean 
	@echo "[INFO] Push_Swap Objects removed"

fclean: clean
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)
	@echo "[INFO] [$(NAME_1)] removed"
	@echo "[INFO] [$(NAME_2)] removed"

re: fclean all
