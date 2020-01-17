# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 19:27:37 by lusanche          #+#    #+#              #
#    Updated: 2020/01/16 19:29:57 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = clang
FLAGS = -Wall -Wextra -Werror
INCLUDES = libft/includes
SRCS = checker_main.c x.c y.c z.c
OBJS = *.o
LIB_DIR = libft/

$(NAME):
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $(SRCS)
	@$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES) -L $(LIB_DIR) -lft
	@echo "[INFO]  Executable [$(NAME)] created (objects remaining in both directories)"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIB_DIR) fclean 
	@echo "[INFO] Objects removed in both directories"
	@rm -f .DS* && rm -f ._*
	@echo "[INFO] ._files removed"


fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Executable [$(NAME)] removed"

re: fclean all
