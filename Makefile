# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/03/02 13:37:04 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

LIB_DIR = libft/
LIB_FILES = ft_atoi ft_isdigit ft_isnumber ft_strcmp ft_memalloc ft_strnew \
			ft_bzero ft_memset

CHECK_FILES = checker ft_check_args
PSH_SWP_FILES = push_swap

CHECK_FILES+= $(addprefix $(LIB_DIR),$(LIB_FILES))
PSH_SWP_FILES+= $(addprefix $(LIB_DIR),$(LIB_FILES))

CC = gcc
FLAG = -Wall -Wextra -Werror -g -I $(INC_DIR)

RM = rm -rf

CCH_DIR = cache/
SRC_DIR = src/
INC_DIR = include/

CHECK_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(CHECK_FILES)))
CHECK_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(CHECK_FILES)))
PSH_SWP_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(PSH_SWP_FILES)))
PSH_SWP_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(PSH_SWP_FILES)))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(CHECK_OBJ)
	@$(CC) $(FLAGS) -o $@ $(CHECK_OBJ)

$(PUSH_SWAP): $(PSH_SWP_OBJ)
	@$(CC) $(FLAGS) -o $@ $(PSH_SWP_OBJ)

$(CCH_DIR)%.o: $(SRC_DIR)%.c | $(CCH_DIR)
	$(CC) $(FLAG) -c $< -o $@

$(CCH_DIR):
	mkdir $@
	mkdir $(CCH_DIR)$(LIB_DIR)

clean:
	$(RM) $(CCH_DIR)
	$(RM) *.o
	$(RM) *.out*

fclean: clean
	$(RM) $(CHECKER)

re: fclean
	$(MAKE) all

norm:
	norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm
