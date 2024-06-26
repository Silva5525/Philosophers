# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/19 16:56:06 by wdegraf           #+#    #+#              #
#    Updated: 2024/06/26 15:11:59 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra -pthread -g 
#| grep -o "eating" | wc -l
# -Wunreachable-code 
#-fsanitize=address -Ofast 
#-fsanitize=thread
# valgrind --leak-check=full ./philo 2 200 200 200
# valgrind --tool=helgrind ./philo 2 200 200 200 # for thread errors in /.philo

HEADERS	:= -I ./include

SRCS	:= main.c utils.c routines.c philo.c

OBJS	:= ${SRCS:.c=.o}


%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) 
	
clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

t: $(NAME)
	./$(NAME) 

ret: re t

.PHONY: all clean fclean re t ret
