# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/04 19:50:48 by taehykim          #+#    #+#              #
#    Updated: 2022/12/04 19:50:49 by taehykim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
AR = ar
CRS = crs

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(CC) -o $@ $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: fclean all clean re
