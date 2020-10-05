# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschmele <sschmele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 17:15:13 by sschmele          #+#    #+#              #
#    Updated: 2020/09/21 21:57:54 by sschmele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra
FLAGS += -g

SOURCES = ft_printf.c \
	   processing_functions.c \
	   int_output.c \
	   output_processing_di.c \
	   output_processing_uob.c \
	   output_processing_x.c \
	   char_and_nonstandard_output.c \
	   float_output.c \
	   help_functions_for_int.c \
	   get_float_components.c \
	   get_fraction.c \
	   other_and_bonus.c \
	   get_integer.c \
	   output_processing_f.c \
	   help_functions_for_float.c

DIR_O = objs

DIR_S = srcs

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS):	$(DIR_O)/%.o: $(DIR_S)/%.c ../includes/ft_printf.h ../includes/libft.h | $(DIR_O)
	gcc $(FLAGS) -c -I ../includes -o $@ $<

$(DIR_O):
	mkdir -p $(DIR_O)

clean:
	/bin/rm -rf $(DIR_O)

fclean: clean
	/bin/rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean
