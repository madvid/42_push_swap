# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/05/27 00:37:48 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS = push_swap
CHK = checker
CM = common
LIBFT = libft

INCLUDE = push_swap.h checker.h
PS_DIR = src_push_swap/
CHK_DIR = src_checker/
INC_DIR = include/
LIB_DIR = libraries/
LIB = -L $(LIB_DIR) -lft

CC = clang
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) #-fsanitize=address -fstack-protector -fsanitize=undefined
RM = rm -rf

### SOURCES AND OBJECTS VARIABLES: ###

CM_FILES =	check_args \
			common_tools \
			ft_issort \
			parser 

PS_FILES =	action_list \
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

CHK_FILES =	check_actions  \
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
	@make -C $(LIBFT)
	@make -C $(CM)
	@echo " $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ $(PS_OBJ) $(LIB)

$(CHK): $(CHK_OBJ)
	@make -C $(LIBFT)
	@make -C $(CM)
	@echo " $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ $(CHK_OBJ) $(LIB)

%.o: %.c
	@echo " $(VIOLET)[$(CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ -c $^

show:
	@echo " $(YELLOW)PS_FILES=$(NOC) $(PS_FILES)\n"
	@echo " $(YELLOW)PS_SRC=$(NOC) $(PS_SRC)\n"
	@echo " $(YELLOW)PS_OBJ=$(NOC) $(PS_OBJ)\n"
	@echo " $(YELLOW)CHK_FILES=$(NOC) $(CHK_FILES)\n"
	@echo " $(YELLOW)CHK_SRC=$(NOC) $(CHK_SRC)\n"
	@echo " $(YELLOW)CHK_OBJ=$(NOC) $(CHK_OBJ)\n"

norm:
	@echo " $(VIOLET)[norminette]$(NOC) $(CYAN)Checking norm of:$(NOC) $(PS) $(CHK)"
	@norminette $(PS_SRC) $(CHK_SRC) $(INC_DIR)$(INCLUDE) | grep -v Norme -B1 || echo "$(VIOLET)[norm] push_swap: $(GREEN)All clear$(NOC)"

norm_all: norm
	@make norm -C $(LIBFT)
	@make norm -C $(CM)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(CM)
	@echo " $(CYAN)Supressing push_swap and checker objects$(NOC)..."
	@rm -rf $(PS_OBJ)
	@rm -rf $(CHK_OBJ)
	@echo " $(RED)-> push_swap and checker objects destroyed$(NOC)"

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(CM)
	@echo " $(CYAN)Supressing $(PS) $(CHK) executables and repository libraries$(NOC)..."
	@rm -rf $(PS)
	@echo " $(RED)->$(PS) executable destroyed$(NOC)"
	@rm -rf $(CHK)
	@echo " $(RED)->$(CHK) executable destroyed$(NOC)"
	@rm -rf $(LIB_DIR)
	@echo " $(RED)->$(LIB_DIR) repository destroyed$(NOC)"

re : fclean all

.PHONY: all clean fclean re norm lib_a
