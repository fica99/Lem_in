
# ------------  PROJECT  ----------------------------------------------------- #

NAME :=	lem-in

# ------------  FLAGS  ------------------------------------------------------- #

FLAGS := -Wall -Wextra #-Werror
FLAGS += -g

# ------------  SOURCE FILES  ------------------------------------------------ #

VALIDATOR_DIR := validator
VALIDATOR := \
			$(VALIDATOR_DIR)/val_start.c \
			$(VALIDATOR_DIR)/val_errors.c \
			$(VALIDATOR_DIR)/val_help_funcs.c \
			$(VALIDATOR_DIR)/val_arguments.c \
			$(VALIDATOR_DIR)/val_first_filter.c \
			$(VALIDATOR_DIR)/val_second_filter.c \
			$(VALIDATOR_DIR)/val_second_filter_rooms.c \
			$(VALIDATOR_DIR)/val_save_rooms.c \

ALGORITHM_DIR := algorithm
ALGORITHM := \
			$(ALGORITHM_DIR)/al_start.c

SOURCES := main.c \
			lemin_graph_proc.c \
			lemin_nodes_proc.c \
			$(VALIDATOR) \
			$(ALGORITHM)

# ------------  DIRECTORIES  ------------------------------------------------- #

DIR_O := objs
DIR_S := srcs
INCLUDE_DIR = includes

# ------------  LIBFT  ------------------------------------------------------- #

LIBFT_DIR := lib/libft
LIB_INCLUDE_DIR := $(LIBFT_DIR)/includes
LIB_PRINTF_INCLUDE_DIR := $(LIBFT_DIR)/ft_printf/includes
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
LIBFT := $(addsuffix .libft , $(LIBFT_DIR)/)

# ------------  RULES  ------------------------------------------------------- #

.PHONY: all clean fclean re

%.libft:  $(LIB_HEADERS)
	make -C $*

LIBS_INCLUDED = -L $(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
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
	make clean --directory $(LIBFT_DIR)

fclean: clean
	@echo "\033[34mDeleting lem_in binary\033[0m"
	/bin/rm -f $(NAME)
	make fclean --directory $(LIBFT_DIR)

re: fclean all
