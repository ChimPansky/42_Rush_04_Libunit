NAME = tests

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g

LIBUNIT_DIR = ../framework
LIBUNIT = $(LIBUNIT_DIR)/libunit.a

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

IFLAGS = -I $(LIBFT_DIR) -I$(LIBUNIT_DIR)
LFLAGS = -L$(LIBFT_DIR) -L$(LIBUNIT_DIR) -lft -lunit

HEADER = ./$(NAME).h

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

FILENAMES = \
	main.c

SRC = $(addprefix ./,$(FILENAMES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(LIBUNIT):
	@make -C $(LIBUNIT_DIR) all clean

$(LIBFT):
	@make -C $(LIBFT_DIR) all clean

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re test