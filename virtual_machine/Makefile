# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/12/18 17:21:17 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DEFINE COLOR *******************/
NC = \033[0m
RED = \033[1;31m
GREEN = \033[0;32m
LOW_GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[0;35m
WHITE = \033[1;37m
YELLOW = \033[1;33m
CYAN = \033[0;36m
BLACK = \033[0;30m
DARK_GRAY = \033[1;30m


#/******************* DIRECTORIES *******************/
SRC_PATH =	src
OBJ_PATH =	obj
INC_PATH =	include
LIB_PATH =	../lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra
OPFLAGS =		-Wno-missing-field-initializers

#/********************** BINARY *********************/
NAME_PATH = ../
NAME = 		corewar

#/********************** SOURCE *********************/
SRC =		corewar.c			\
			check_parameters.c	\
			check_parameters2.c	\
			check_parameters3.c	\
			convert.c			\
			exit.c				\
			exit2.c				\
			exit3.c				\
			free.c				\
			get_action.c		\
			get_value.c			\
			initialization.c 	\
			print_ram_curses.c 	\
			use_ncurses.c	 	\
			use_ncurses2.c	 	\
			input_ncurses.c 	\
			instruction.c		\
			instruction2.c		\
			instruction3.c		\
			instruction4.c		\
			print_instruction.c	\
			print_instruction2.c\
			print_instruction3.c\
			print_function.c	\
			print_memory.c		\
			lib_list.c			\
			load_in_ram.c		\
			run_vm.c			\
			run_vm_execute.c			\


LIBNAME =	libft/libft.a \

#/********************** PATH  *********************/
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJ	 =		$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))
HDRS =		$(addprefix $(INC_PATH)/,corewar.h ft_printf.h get_next_line.h libft.h op.h)

###################################################
#/********************** RULES *********************/

all : $(NAME_PATH)$(NAME)

$(NAME_PATH)$(NAME) : $(OBJ) $(HDRS) Makefile $(LIBP)
	@$(CC) $(CFLAGS) -lncurses $(OBJ) $(LIBP) -o $(NAME_PATH)$(NAME)
	@echo "\n$(PURPLE)Executable $(NAME)\tdone$(NC)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HDRS) Makefile $(LIBP)
	@echo "$(GREEN)o\c"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(OPFLAGS) -c $< -o $@ $(INCP)

clean :
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@rm -rf $(NAME_PATH)$(NAME)

re: fclean all

debug : $(OBJ)
	@echo "$(PURPLE) --Linking--\t\t"
	$(CC) -lncurses -o $(NAME_PATH)$(NAME) $^ $(LIBP) -fsanitize=address -O1 -fno-omit-frame-pointer
