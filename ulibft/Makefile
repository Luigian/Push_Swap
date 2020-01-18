# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 10:41:38 by lusanche          #+#    #+#              #
#    Updated: 2020/01/17 18:31:21 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = -I libft.h -I ft_printf/ft_printf.h
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_chrstr.c \
	  ft_count_words.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_islower.c \
	  ft_isprint.c \
	  ft_isspecial.c \
	  ft_isupper.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_nbrlen.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_stranew.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_swap.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_word_len.c \
	  get_next_line.c \
	  ft_printf/ft_printf_bonus.c \
	  ft_printf/ft_printf_cspd.c \
	  ft_printf/ft_printf_exponent.c \
	  ft_printf/ft_printf_flags.c \
	  ft_printf/ft_printf_float.c \
	  ft_printf/ft_printf_itoa.c \
	  ft_printf/ft_printf_master.c \
	  ft_printf/ft_printf_ouxf.c \
	  ft_printf/ft_printf_round.c \
	  ft_printf/ft_printf_store.c \
	  ft_printf/ft_printf_time.c \
	  ft_printf/ft_printf_tools.c
OBJ = *.o

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) $(INCLUDES) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[INFO] [$(NAME)] created"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "[INFO] Libft Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] [$(NAME)] removed"

re: fclean all
