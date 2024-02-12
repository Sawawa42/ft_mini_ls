# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syamasaw <syamasaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 15:07:33 by syamasaw          #+#    #+#              #
#    Updated: 2024/02/12 15:01:18 by syamasaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_mini_ls
BNAME = $(addsuffix _bonus, $(NAME))

HEADER_DIR = ./mandatory/includes/
HEADERS := ft_mini_ls.h
HEADERS := $(addprefix $(HEADER_DIR), $(HEADERS))

BHEADER_DIR = ./bonus/includes/
BHEADERS := ft_mini_ls_bonus.h
BHEADERS := $(addprefix $(BHEADER_DIR), $(BHEADERS))

SRC_DIR = ./mandatory/srcs/
SRCS = main.c ls_current.c putstrs_oneline.c utils.c sorts.c
SRCS := $(addprefix $(SRC_DIR), $(SRCS))

BSRC_DIR = ./bonus/srcs/
BSRCS = main_bonus.c\
		ls_single_path_bonus.c ls_paths_bonus.c\
		set_option_bonus.c set_arg_paths_bonus.c set_data_bonus.c\
		sort_t_data_bonus.c\
		put_dir_bonus.c put_result_bonus.c put_result_oneline_bonus.c\
		put_result_comma_bonus.c put_str_color_bonus.c\
		utils_bonus.c ft_funcs_bonus.c exit_funcs_bonus.c
BSRCS := $(addprefix $(BSRC_DIR), $(BSRCS))

TMP_DIR = ./obj/
OBJ_DIR = $(addprefix $(TMP_DIR),mandatory/)
BOBJ_DIR = $(addprefix $(TMP_DIR),bonus/)

OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
BOBJS = $(patsubst $(BSRC_DIR)%.c,$(BOBJ_DIR)%.o,$(BSRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(HEADER_DIR)
BIFLAGS = -I$(BHEADER_DIR)

ifdef BONUS_FLAG
NAME := $(BNAME)
IFLAGS := $(BIFLAGS)
OBJS := $(BOBJS)
SRC_DIR := $(BSRC_DIR)
OBJ_DIR := $(BOBJ_DIR)
endif

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) 
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus:
	make BONUS_FLAG=1

clean:
	rm -rf $(TMP_DIR)

fclean: clean
	rm -f $(NAME) $(BNAME)

re:
	rm -rf $(OBJ_DIR)
	@make all
ifeq ($(shell ls obj 2> /dev/null | grep "bonus"), bonus)
	rm -rf $(BOBJ_DIR)
	@make bonus
endif

.PHONY: all bonus clean fclean re