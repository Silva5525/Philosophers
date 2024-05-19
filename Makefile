# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:56:06 by wdegraf           #+#    #+#              #
#    Updated: 2024/05/19 17:10:58 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -g -Wunreachable-code 
#-g -fsanitize=address -Ofast 
# valgrind --leak-check=full ./meinProgramm

LIBFT	:= ./libft

HEADERS	:= -I ./include -I $(LIBFT)

LIBS	:= -L$(LIBFT) -lft

SRCS	:= main.c

OBJS	:= ${SRCS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME) 
	
clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

t: $(NAME)
	./$(NAME) 

ret: re t

.PHONY: all, clean, fclean, re, libmlx, libft
