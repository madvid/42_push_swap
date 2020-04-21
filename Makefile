# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/04/13 19:06:18 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

LIB_DIR = libft/
CCH_DIR = cache/
SRC_DIR = src/
INC_DIR = include/

LIB_FILES = ft_atoi ft_isdigit ft_isnumber ft_strcmp ft_memalloc ft_strnew \
			ft_bzero ft_memset ft_table_int int_tab_dup ft_putnbr ft_putstr \
			ft_putchar

COMMON_FILES = tools_print ft_check_args tools_intab
CHECK_FILES = checker init_tab_actions check_actions
PSH_SWP_FILES = push_swap swap push rotate rev_rotate naive_test_sorts quicksort \
				quicksort_2stacks ft_stack_split sort_stack tools_info push_back \
				ft_issort ft_stat_tools

CHECK_FILES+= $(addprefix $(LIB_DIR),$(LIB_FILES))
PSH_SWP_FILES+= $(addprefix $(LIB_DIR),$(LIB_FILES))

CHECK_FILES+= $(COMMON_FILES)
PSH_SWP_FILES+= $(COMMON_FILES)

CHECK_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(CHECK_FILES)))
CHECK_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(CHECK_FILES)))
PSH_SWP_SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(PSH_SWP_FILES)))
PSH_SWP_OBJ = $(addprefix $(CCH_DIR),$(addsuffix .o,$(PSH_SWP_FILES)))

CC = gcc
FLAG = -Wall -Wextra -Werror -g -I $(INC_DIR)
RM = rm -rf


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
	$(RM) $(CHECKER) $(PUSH_SWAP)

re: fclean
	$(MAKE) all

norm:
	norminette $(SRC) $(INC_DIR) | grep -v Norme -B1 || true

.PHONY: all clean fclean re norm