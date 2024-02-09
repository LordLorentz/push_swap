
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -g
CC = cc
ARCHIVE = ar -rcs

LIBFT	= ./libft

LINKERS	= -lm

LIBS	= $(LIBFT)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT)/include -I src

HEADER = src/push_swap.h

FILES := \
	agent_sort.c \
	curse_stack.c \
	discriminant.c \
	error_handling.c \
	inquisition.c \
	jumptable.c \
	main.c \
	normalize_stack.c \
	read_stack.c \
	instructions/pa.c \
	instructions/pb.c \
	instructions/ra.c \
	instructions/rb.c \
	instructions/rra.c \
	instructions/rrb.c \
	instructions/rr.c \
	instructions/rrr.c \
	instructions/sa.c \
	instructions/sb.c \
	instructions/ss.c


OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

all: $(LIBFT) $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT) all

$(NAME): build $(OBJECTS) $(LIBS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) $(LINKERS) -o $(NAME)

fsanitize: build $(OBJECTS)
	$(CC) -fsanitize=address -g $(CFLAGS) $(OBJECTS) $(LINKERS) $(LIBS) -o $(NAME)

build:
	mkdir build
	mkdir build/instructions

build/%.o: src/%.c $(HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re libft fsanitize