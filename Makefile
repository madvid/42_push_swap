# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/05/29 01:13:10 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CHK = checker
CM = common

INCLUDE = push_swap.h checker.h
PS_DIR = src_push_swap/
CHK_DIR = src_checker/
INC_DIR = include/
LIB_DIR = libraries/
LIBFT_DIR = libft
LIB_NAME = libft.a
LIB = -L $(LIB_DIR) -lft
LIBFT = $(LIBFT_DIR)/$(LIB_NAME)

CC = clang
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) #-fsanitize=address -fstack-protector -fsanitize=undefined
RM = rm -rf

### SOURCES AND OBJECTS VARIABLES: ###

LIBFT_FILES =	ft_atoi \
				ft_bzero \
				ft_eraser \
				ft_free_table_str \
				ft_isdigit \
				ft_isnumber \
				ft_memalloc \
				ft_memcpy \
				ft_memncat \
				ft_memset \
				ft_putchar \
				ft_putnbr \
				ft_putstr \
				ft_strchr \
				ft_strcmp \
				ft_strcpy \
				ft_strdel \
				ft_strdup \
				ft_strlen \
				ft_strnew \
				ft_strsplit \
				ft_strsub \
				ft_table_2_str \
				ft_tablecpy \
				ft_tablecpy_wtht_motif \
				ft_table_int \
				ft_tablelen \
				ft_table_nb_char \
				ft_table_str \
				int_tab_dup \
				get_next_line_lite

LIBFT_SRC = $(addprefix libft/, $(addsuffix .c,$(LIBFT_FILES)))


CM_FILES =		check_args \
				common_tools \
				ft_issort \
				parser

CM_SRC = $(addprefix common/, $(addsuffix .c,$(CM_FILES)))

PS_FILES =		action_list \
				final_opti \
				ft_check_full \
				ft_table_nb_motif \
				optimal_small_sort \
				push_back \
				push_swap \
				quicksort \
				quicksort_2stacks \
				sort_stack1 \
				sort_stack2 \
				sorting \
				stack_split \
				stat_tools \
				tools_info \
				tools_intab \
				tools_print \
				rev_rotate \
				rotate \
				push \
				swap

PS_SRC = $(addprefix $(PS_DIR), $(addsuffix .c,$(PS_FILES)))
PS_OBJ = $(PS_SRC:.c=.o)

CHK_FILES =		check_actions  \
				checker \
				init_tab_actions \
				rev_rotate \
				rotate \
				push \
				swap

CHK_SRC = $(addprefix $(CHK_DIR), $(addsuffix .c,$(CHK_FILES)))
CHK_OBJ = $(CHK_SRC:.c=.o)

### COLORS ###

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
VIOLET = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

### RULES: ###

all: $(PS) $(CHK) 

$(PS): $(PS_OBJ)
	@echo "\n $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ $(PS_OBJ) $(LIB)

$(CHK): $(CHK_OBJ)
	@echo "\n $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ $(CHK_OBJ) $(LIB)

$(PS_OBJ): $(INC_DIR)/push_swap.h | $(CM)

$(CHK_OBJ): $(INC_DIR)/checker.h | $(CM) 

%.o: %.c
	@echo " $(VIOLET)[$(CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ -c $<

$(CM): $(LIBFT) $(CM_SRC)
	@make -sC $(CM)

$(LIBFT): $(LIBFT_SRC)
	@make -sC $(LIBFT_DIR)

show:
	@echo " $(YELLOW)PS_FILES=$(NOC) $(PS_FILES)\n"
	@echo " $(YELLOW)PS_SRC=$(NOC) $(PS_SRC)\n"
	@echo " $(YELLOW)PS_OBJ=$(NOC) $(PS_OBJ)\n"
	@echo " $(YELLOW)CHK_FILES=$(NOC) $(CHK_FILES)\n"
	@echo " $(YELLOW)CHK_SRC=$(NOC) $(CHK_SRC)\n"
	@echo " $(YELLOW)CHK_OBJ=$(NOC) $(CHK_OBJ)\n"

norm:
	@echo "\n $(VIOLET)[norminette]$(NOC) $(CYAN)Checking norm of:$(NOC) $(PS) $(CHK)"
	@norminette $(PS_SRC) $(CHK_SRC) $(INC_DIR)$(INCLUDE) | grep -v Norme -B1 || echo "$(VIOLET)[norm] push_swap: $(GREEN)All clear$(NOC)"

norm_all: norm
	@make norm -C $(LIBFT_DIR)
	@make norm -C $(CM)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(CM)
	@echo "\n $(CYAN)Supressing push_swap and checker objects$(NOC)..."
	@rm -rf $(PS_OBJ)
	@rm -rf $(CHK_OBJ)
	@echo " $(RED)-> push_swap and checker objects destroyed$(NOC)"

clean_2:
	@echo "\n $(CYAN)Supressing push_swap and checker objects$(NOC)..."
	@rm -rf $(PS_OBJ)
	@rm -rf $(CHK_OBJ)
	@echo " $(RED)-> push_swap and checker objects destroyed$(NOC)"

fclean: clean_2
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(CM)
	@echo " \n$(CYAN)Supressing $(PS) $(CHK) executables and repository libraries$(NOC)..."
	@rm -rf $(PS)
	@echo " $(RED)->$(PS) executable destroyed$(NOC)"
	@rm -rf $(CHK)
	@echo " $(RED)->$(CHK) executable destroyed$(NOC)"
	@rm -rf $(LIB_DIR)
	@echo " $(RED)->$(LIB_DIR) repository destroyed$(NOC)"

re : fclean all

.PHONY: all show norm_all norm clean clean_2 fclean re
