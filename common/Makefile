# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:48:33 by mdavid            #+#    #+#              #
#    Updated: 2020/05/29 01:13:58 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = common

CC = clang
INCLUDE = common.h
INC_DIR = ../include/
LIB_DIR = ../libraries/
LIB_A = ../libft.a
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)#-fsanitize=address -fstack-protector -fsanitize=undefined

### SOURCES AND OBJECTS VARIABLES ###

CM_FILES =	check_args \
			common_tools \
			ft_issort \
			parser

CM_SRC = $(addsuffix .c,$(CM_FILES))
CM_OBJ = $(CM_SRC:.c=.o)

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
 
 ### RULES ###

all : $(NAME)

$(NAME) : $(CM_OBJ)
	@echo "\n $(VIOLET)[ar rcs] $(CYAN)Updating librairy:$(NOC) $(LIB_DIR)$(LIB_A)"
	@ar rs $(LIB_DIR)libft.a $^
	@echo " $(VIOLET)[ar rcs] $(NOC)--> $(GREEN)Static librairy updated:$(NOC) $(LIB_DIR)$(LIB_A)"

$(CM_OBJ): $(INC_DIR)$(INCLUDE)

%.o: %.c
	@echo "  $(VIOLET)[$(CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ -c $<

norm :
	@echo "\n $(VIOLET)[norminette]$(NOC) $(CYAN)Checking norm of common:$(NOC)"
	@norminette $(PS_SRC) $(INC_DIR)$(INCLUDE) | grep -v Norme -B1 || echo "$(VIOLET)[norm] common: $(GREEN)All clear$(NOC)"
	@$(MAKE) -C norm

clean :
	@echo "\n $(CYAN)Supressing common objects$(NOC)..."
	@rm -rf $(CM_OBJ)
	@echo "$(RED)-> common objects destroyed$(NOC)"

fclean : clean
	@echo "\n $(CYAN)Supressing static library$(NOC)..."
	@rm -rf $(LIB_DIR)$(NAME)
	@echo "$(RED)-> libft.a destroyed$(NOC)"


re : fclean all
