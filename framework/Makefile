NAME = libunit.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS += -g

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

IFLAGS = -I $(LIBFT_DIR) -I./
LFLAGS = -L$(LIBFT_DIR) -lft

SOURCE_DIR = src
HEADER = ./libunit.h

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

FILENAMES = unit.c \
			logging.c
			# executor.c \

SRC = $(addprefix $(SOURCE_DIR)/,$(FILENAMES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar -rs $(NAME) $(OBJ)
	@echo "$(GREEN)Library $(NAME) created!$(DEF_COLOR)"

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

bonus: all
