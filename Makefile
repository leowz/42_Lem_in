# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/01/30 19:52:28 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = lem-in

LIBDIR = libft

LIB = libft.a

SRCS = lem_in.c helper.c li_get_input.c li_get_input_util2.c li_get_input_util.c \
	   li_check.c li_util.c li_print.c li_resolve.c li_search_path.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADER_DIR = libft

HEADER = lem_in.h

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
#  # ==================

all: $(NAME)

$(NAME): $(LIBDIR)/$(LIB) $(OBJS)
	@$(CC) $(OBJS) -L$(LIBDIR)/ -lft -o $@
	@printf $(GREEN)"\nFinish lem-in linking\n"$(EOC)

$(LIBDIR)/$(LIB):
	@make -C $(LIBDIR)/ fclean && make -C $(LIBDIR)/

%.o: %.c $(HEADER)
	@$(CC) -c $(CFLAGS) $< -I. -I$(HEADER_DIR) -o $@
	@printf $(GREEN)"\r\E[KFinish lem-in compiling"$(EOC)

clean:
	@/bin/rm -f $(OBJS) 
	@printf $(GREEN)"Lem-in clean\n"$(EOC)
	@make -C $(LIBDIR)/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(GREEN)"Lem-in fclean\n"$(EOC)
	@make -C $(LIBDIR)/ fclean

re: fclean
	@make

.PHONY: clean fclean all
