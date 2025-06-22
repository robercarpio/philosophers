# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rober <rober@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:18:53 by rober             #+#    #+#              #
#    Updated: 2025/06/18 17:09:18 by rober            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		utils.c \
		aux/ft_bzero.c \
		aux/ft_calloc.c \
		aux/ft_memcpy.c \
		aux/ft_split.c \
		aux/ft_strdup.c \
		aux/ft_strlcpy.c \
		aux/ft_strlen.c \
		aux/ft_substr.c \

NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCLUDES = philosophers.h

all: $(NAME)
	@echo "OK"
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "compilation completed"

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "fully clean"

re: fclean all

.PHONY: clean fclean all re