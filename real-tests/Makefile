NAME = real-tests

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g

LIBUNIT_DIR = ../framework
LIBUNIT = $(LIBUNIT_DIR)/libunit.a

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

IFLAGS = -I $(LIBFT_DIR) -I$(LIBUNIT_DIR) -I./
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

ROUTINE1_DIR = ft_isalpha
ROUTINE2_DIR = ft_isdigit

FILES1 = \
	00_launcher.c \
	01_test_lower_case.c \
	02_test_upper_case.c \
	03_test_digit.c \
	04_test_special.c \
	05_test_null_terminator.c

SRC = main.c
SRC += $(addprefix $(ROUTINE1_DIR)/,$(FILES1))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBUNIT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

$(LIBUNIT):
	@make -C $(LIBUNIT_DIR) all clean

$(LIBFT):
	@make -C $(LIBFT_DIR) all clean

test: all
	./$(NAME)

#!!!!!!!!!!!!!!
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re test
