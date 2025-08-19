# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarpio-cyepes <rcarpio-cyepes@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 16:18:53 by rober             #+#    #+#              #
#    Updated: 2025/08/19 20:06:53 by rcarpio-cye      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		utils.c \
		aux/ft_atol.c \
		aux/ft_bzero.c \
		aux/ft_calloc.c \
		aux/ft_memcpy.c \
		aux/ft_split.c \
		aux/ft_strdup.c \
		aux/ft_strlcpy.c \
		aux/ft_strlen.c \
		aux/ft_substr.c \
		aux/getters_setters.c \
		aux/is_x.c \
		aux/safe_functions.c \
		aux/valid_number.c \
		dinner/dinner.c \
		dinner/sync_utils.c \
		dinner/write.c \
		init/init.c \
		parse/parse.c \
		monitor/monitor.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = philosophers.h aux/aux.h dinner/dinner.h init/init.h parse/parse.h

all: $(NAME)

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

.PHONY: all clean fclean re
