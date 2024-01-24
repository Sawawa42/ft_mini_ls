# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:07:33 by syamasaw          #+#    #+#              #
#    Updated: 2024/01/24 13:48:42 by syamasaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c ls_work.c putstrs_oneline.c utils.c sorts.c

OBJ_DIR = ./obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re