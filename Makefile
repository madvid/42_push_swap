# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/02/29 18:30:39 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

LIB_DIR = libft/
LIB_FILES = ft_atoi ft_isdigit ft_isnumber

FILES_CHECK = checker ft_chek_args
FILES_PSH_SWP = push_swap

FILES_CHECK+= $(addprefix $(LIB_DIR),$(LIB_FILES))
FILES_PSH_SWP+= $(addprefix $(LIB_DIR),$(LIB_FILES))

CC = gcc
FLAG = -Wall -Wextra -Werror -g -I $(INC_DIR)

RM = rm -rf

CCH_DIR = cache/
SRC_DIR = src/
INC_DIR = include/

SRC_CHECK = $(addprefix $(SRC_DIR),$(addsuffix .c,$(FILES_CHECK)))
SRC_PSH_SWP = $(addprefix $(SRC_DIR),$(addsuffix .c,$(FILES_PSH_SWP)))
OBJ_CHECK = $(addprefix $(CCH_DIR),$(addsuffix .o,$(FILES_CHECK)))
OBJ_PSH_SWP = $(addprefix $(CCH_DIR),$(addsuffix .o,$(FILES_PSH_SWP)))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJ_CHECK)

$(PUSH_SWAP): $(OBJ_PSH_SWP)

$(CCH_DIR_CHECK)%.o: $(SRC_CHECK)%.c | $(CCH_DIR)
	$(CC) $(FLAG) -c $< -o $@
#if .o is older than .c, then do the content
# $< means the first prerequisite
# | The names of all the order-only prerequisites, with spaces between them.

$(CCH_DIR_PSH_SWP)%.o: $(SRC_PSH_SWP)%.c | $(CCH_DIR)
	$(CC) $(FLAG) -c $< -o $@
#if .o is older than .c, then do the content
# $< means the first prerequisite
# | The names of all the order-only prerequisites, with spaces between them.

$(CCH_DIR):
	mkdir $@
	mkdir $(CCH_DIR)$(LIB_DIR)

clean:
	$(RM) $(CCH_DIR)
	$(RM) *.o
	$(RM) *.out*

fclean: clean
	$(RM) $(CHECKER) $(PUSH_SWAP)

re: fclean
	$(MAKE) all

norm:
	norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
