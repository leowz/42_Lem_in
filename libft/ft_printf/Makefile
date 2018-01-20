# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zweng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 18:11:43 by zweng             #+#    #+#              #
#    Updated: 2018/01/18 16:07:06 by zweng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

LIB = ../libft.a

LIBDIR = ../

SRCS = ft_printf.c ft_vdprintf.c ft_convert.c ft_rpstr.c ft_wchar.c \
	   ft_rpstr_util.c ft_rpstr_util2.c ft_rpstr_format.c ft_convert_util.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

LIBSRCS = $(wildcard $(LIBDIR)*.c)

LIBOBJS = $(patsubst %.c, %.o, $(LIBSRCS))

HEADER_DIR = ../

HEADER = ft_printf.h ft_printf_private.h 

CFLAGS = -Wall -Wextra -Werror
# === Colors ===
# usage "$(WHITE) Hello $(END)"
WHITE="\033[1;37m"
RED="\033[1;31m"
GREEN="\033[1;32m"
BLACK="\033[1;30m"
END="\033[0;0m"
# # ==============

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@ar rc $@ $(OBJS) $(LIBOBJS)
	@printf $(GREEN)"\r\E[Kft_printf linking finish\n"$(END)

$(LIB): $(LIBSRCS)
	@make -C $(LIBDIR) fclean && make -C $(LIBDIR)

%.o: %.c $(HEADER)
	@$(CC) -c $(CFLAGS) $< -I. -I$(HEADER_DIR) -o $@
	@printf $(GREEN)"\r\E[Kcompiling %s"$(GREEN) $<

clean:
	@/bin/rm -f $(OBJS) 
	@printf $(GREEN)"ft_printf clean\n"$(END)

fclean: clean
	@/bin/rm -f $(NAME)
	@printf $(GREEN)"ft_printf fclean\n"$(END)

re: fclean
	@make

.PHONY:clean fclean all
