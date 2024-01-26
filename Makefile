
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -g
CC = cc
ARCHIVE = ar -rcs

LIBFT	= ./libft

LINKERS	= -lm

LIBS	= $(LIBFT)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT)/include

FILES := \
	curse_stack.c \
	error_handling.c \
	main.c \
	normalize_stack.c \
	read_stack.c \


OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

all: $(LIBFT) $(NAME)

bonus: all

$(LIBFT):
	@make -C $(LIBFT) all

$(NAME): build $(OBJECTS) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

fsanitize: build $(OBJECTS)
	@$(CC) -fsanitize=address -g $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

build:
	@mkdir build

build/%.o: src/%.c
	@$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJECTS)

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)
	@rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re libft fsanitize