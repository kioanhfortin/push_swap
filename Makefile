# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 11:25:52 by kfortin           #+#    #+#              #
#    Updated: 2022/10/15 11:36:38 by kfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c push_swap_utilis.c ft_split.c ft_op_1.c ft_op_2.c\
	ft_op_utilis.c ft_small_sort.c ft_indexation.c ft_big_sort_utilis.c\
	ft_medium_sort.c ft_big_sort.c ft_big_sort_1.c ft_big_sort_2.c\
	ft_parsing.c push_swap_utilis1.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all :	$(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	
clean :
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all