# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/11 16:48:33 by weilin            #+#    #+#              #
#    Updated: 2020/05/22 19:44:15 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CM = common
LIBFT = libft

INCLUDE = push_swap.h
PS_DIR = src_push_swap/
INC_DIR = include/
LIB_DIR = libraries/
LIB = -L$(LIB_DIR) -lft

CC = clang
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR) #-fsanitize=address -fstack-protector -fsanitize=undefined
RM = rm -rf

### SOURCES AND OBJECTS VARIABLES: ###

PS_FILES =	action_list \
			final_opti \
			ft_issort \
			ft_table_nb_motif \
			ft_check_full \
			optimal_small_sort \
			push_back \
			push_swap \
			quicksort \
			quicksort_2stacks \
			rev_rotate \
			rotate \
			stack_split \
			stat_tools \
			sort_stack1 \
			sort_stack2 \
			swap push \
			tools_info \
			tools_intab \
			tools_print

PS_SRC = $(addprefix $(PS_DIR), $(addsuffix .c,$(PS_FILES)))
PS_OBJ = $(PS_SRC:.c=.o)

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

all: $(NAME)

$(NAME): $(PS_OBJ)
	@make -C $(LIBFT)
	@make -C $(CM)
	@echo " $(VIOLET)[$(CC)] $(CYAN)Constructing executable:$(NOC) $@"
	$(CC) $(FLAGS) $(LIB) -o $@ $(PS_OBJ)

%.o: %.c
	@echo " $(VIOLET)[$(CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ -c $^

show:
	@echo " $(YELLOW)PS_FILES=$(NOC) $(PS_FILES)\n"
	@echo " $(YELLOW)PS_SRC=$(NOC) $(PS_SRC)\n"
	@echo " $(YELLOW)PS_OBJ=$(NOC) $(PS_OBJ)\n"

norm:
	@echo " $(VIOLET)[norminette]$(NOC) $(CYAN)Checking norm of:$(NOC) $(NAME)"
	@norminette $(PS_SRC) $(INC_DIR)$(INCLUDE) | grep -v Norme -B1 || echo "$(VIOLET)[norm] push_swap: $(GREEN)All clear$(NOC)"

norm_all: norm
	@make norm -C $(LIBFT)
	@make norm -C $(CM)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(CM)
	@echo " $(CYAN)Supressing push_swap objects$(NOC)..."
	@rm -rf $(PS_OBJ)
	@echo " $(RED)-> push_swap objects destroyed$(NOC)"

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(CM)
	@echo " $(CYAN)Supressing $(NAME) executable and repository libraries$(NOC)..."
	@rm -rf $(NAME)
	@echo " $(RED)->$(NAME) executable destroyed$(NOC)"
	@rm -rf $(LIB_DIR)
	@echo " $(RED)->$(LIB_DIR) repository destroyed$(NOC)"

re : fclean all

.PHONY: all clean fclean re norm lib_a
