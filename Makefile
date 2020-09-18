# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara <aashara@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 12:55:39 by aashara-          #+#    #+#              #
#    Updated: 2020/09/18 11:32:14 by aashara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ------------  PROJECT  ----------------------------------------------------- #

NAME :=	lem-in

# ------------  FLAGS  ------------------------------------------------------- #

FLAGS := -Wall -Wextra #-Werror
FLAGS += -g

# ------------  SOURCE FILES  ------------------------------------------------ #

VALIDATOR_DIR := validator
VALIDATOR := $(VALIDATOR_DIR)/val_start.c

ALGORITHM_DIR := algorithm
ALGORITHM := $(ALGORITHM_DIR)/al_start.c

SOURCES :=	main.c \
			$(VALIDATOR) \
			$(ALGORITHM)

# ------------  DIRECTORIES  ------------------------------------------------- #

DIR_O := objs
DIR_S := srcs
INCLUDE_DIR = includes

# ------------  LIBFT  ------------------------------------------------------- #

LIB_INCLUDE_DIR := libft/includes
LIB_PRINTF_INCLUDE_DIR := libft/ft_printf/includes
LIB_HEADERS := \
			$(wildcard $(LIB_INCLUDE_DIR)/*.h) \
			$(wildcard $(LIB_PRINTF_INCLUDE_DIR)/*.h)

# ------------  INCLUDE FILES  ------------------------------------------------ #

INCLUDES := -I $(INCLUDE_DIR) -I $(LIB_INCLUDE_DIR) -I $(LIB_PRINTF_INCLUDE_DIR)

# ------------  FILEPATHS  --------------------------------------------------- #

SRCS := $(addprefix $(DIR_S)/,$(SOURCES))
OBJS := $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
LIBFT = $(addsuffix .libft , libft/)

# ------------  RULES  ------------------------------------------------------- #

.PHONY: all clean fclean re

%.libft:  $(LIB_HEADERS)
	make -C $*

LIBS_INCLUDED = -Llibft -lft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBS_INCLUDED)

$(OBJS): $(DIR_O)/%.o: $(DIR_S)/%.c $(wildcard $(INCLUDE_DIR)/*.h)
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(VALIDATOR_DIR)
	mkdir -p $(DIR_O)/$(ALGORITHM_DIR)

	gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

clean:
	/bin/rm -rf $(DIR_O)
	make clean --directory ./libft

fclean: clean
	/bin/rm -f $(NAME)
	make fclean --directory ./libft

re: fclean all
