
# ------------  PROJECT  ----------------------------------------------------- #

NAME :=	lem_in

# ------------  FLAGS  ------------------------------------------------------- #

FLAGS := -Wall -Wextra #-Werror
FLAGS += -g
FLAGS += -MMD -MP

# ------------  SOURCE FILES  ------------------------------------------------ #

VALIDATOR_DIR := validator
VALIDATOR := \
			$(VALIDATOR_DIR)/val_start.c

ALGORITHM_DIR := algorithm
ALGORITHM := \
			$(ALGORITHM_DIR)/al_start.c
			$(ALGORITHM_DIR)/al_bellman_ford.c

SOURCES := main.c \
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

# ------------  INCLUDE FILES  ----------------------------------------------- #

INCLUDES := \
			-I $(INCLUDE_DIR) \
			-I $(LIB_INCLUDE_DIR) \
			-I $(LIB_PRINTF_INCLUDE_DIR)

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
	@echo "\033[32;01mCompiling lem_in...\033[0m"
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBS_INCLUDED)
	@echo "\033[32;01mlem_in is ready\033[0m"

$(OBJS): $(DIR_O)/%.o: $(DIR_S)/%.c $(wildcard $(INCLUDE_DIR)/*.h) | $(DIR_O)

	gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

$(DIR_O):
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(VALIDATOR_DIR)
	mkdir -p $(DIR_O)/$(ALGORITHM_DIR)

clean:
	@echo "\033[34mDeleting lem_in o-files\033[0m"
	/bin/rm -rf $(DIR_O)
	make clean --directory ./libft

fclean: clean
	@echo "\033[34mDeleting lem_in binary\033[0m"
	/bin/rm -f $(NAME)
	make fclean --directory ./libft

re: fclean all
