# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: md4 <md4@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:48:33 by mdavid            #+#    #+#              #
#    Updated: 2020/05/29 00:49:58 by md4              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang
INCLUDE = libft.h
INC_DIR = ../include/
LIB_DIR = ../libraries/
FLAGS = -Wall -Wextra -Werror -g -I$(INC_DIR)#-fsanitize=address -fstack-protector -fsanitize=undefined

### SOURCES AND OBJECTS VARIABLES ###

LIB_FILES =	ft_atoi \
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

LIB_SRC = $(addsuffix .c,$(LIB_FILES))
LIB_OBJ = $(LIB_SRC:.c=.o)

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

$(NAME) : $(LIB_OBJ) $(INC_DIR)$(INCLUDE)
	@mkdir -p $(LIB_DIR)
	@echo " $(VIOLET)[ar rcs] $(CYAN)Constructing librairy:$(NOC) $(LIB_DIR)$@"
	@ar rc $(LIB_DIR)$(NAME) $^
	@echo " $(VIOLET)[ar rcs] $(NOC)--> $(GREEN)Static librairy created:$(NOC) $(LIB_DIR)$@"

%.o : %.c
	@echo "  $(VIOLET)[$(CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
	@$(CC) $(FLAGS) -o $@ -c $<

norm :
	@echo " $(VIOLET)[norminette]$(NOC) $(CYAN)Checking norm of libft:$(NOC)"
	@norminette $(LIB_SRC) $(INC_DIR)$(INCLUDE) | grep -v Norme -B1 || echo "$(VIOLET)[norm] libft: $(GREEN)All clear$(NOC)"
	 
clean :
	@echo " $(CYAN)Supressing libft objects$(NOC)..."
	@rm -rf $(LIB_OBJ)
	@echo " $(RED)-> libft objects destroyed$(NOC)"

fclean : clean
	@echo " $(CYAN)Supressing static library$(NOC)..."
	@rm -rf $(LIB_DIR)$(NAME)
	@echo " $(RED)-> $(LIB_DIR)$(NAME) destroyed$(NOC)"


re : fclean all
