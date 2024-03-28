
NAME	= push_swap
TITRATE	= titrate

CFLAGS	= -Wall -Wextra -Werror -O3 -march=native -g
CC		= cc
ARCHIVE = ar -rcs

LIBFT	= ./libft

LINKERS	= -lm

LIBS	= $(LIBFT)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT)/include -I include

HEADER = include/push_swap.h
TITRATE_HEADER = include/titrate.h

FILES := \
	sort/agent_sort.c \
	sort/council_sort.c \
	sort/main.c \
	titrate/control_dsc.c \
	titrate/control_cycle.c \
	titrate/hash_stacks.c \
	titrate/hashlist.c \
	titrate/interpret_result.c \
	titrate/test_cycle.c \
	titrate/titrate.c \
	tools/discriminant.c \
	tools/distillate.c \
	tools/branch.c \
	tools/curse_stack.c \
	tools/dsclist.c \
	tools/hash_interface.c \
	tools/jumptable.c \
	tools/print_discriminant.c \
	tools/error_handling.c \
	tools/instructions/sa.c \
	tools/instructions/sb.c \
	tools/instructions/ss.c \
	tools/instructions/pa.c \
	tools/instructions/pb.c \
	tools/instructions/ra.c \
	tools/instructions/rb.c \
	tools/instructions/rr.c \
	tools/instructions/rra.c \
	tools/instructions/rrb.c \
	tools/instructions/rrr.c \
	tools/proposal.c \
	tools/inquisition.c \
	tools/read_stack.c \
	tools/normalize_stack.c

OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

SORT_OBJ := $(filter build/sort/%, $(OBJECTS))
TITRATE_OBJ := $(filter build/titrate/%, $(OBJECTS))
TOOLS_OBJ := $(filter build/tools/%, $(OBJECTS))

all: $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT) all

$(NAME): $(LIBFT) build $(SORT_OBJ) $(TOOLS_OBJ) $(LIBS) $(HEADER)
	$(CC) $(CFLAGS) $(SORT_OBJ) $(TOOLS_OBJ) $(LIBS) $(LINKERS) -o $(NAME)

$(TITRATE): $(LIBFT) build $(TITRATE_OBJ) $(TOOLS_OBJ) $(LIBS) $(HEADER) $(TITRATE_HEADER)
	$(CC) $(CFLAGS) $(TITRATE_OBJ) $(TOOLS_OBJ) $(LIBS) $(LINKERS) -o $(TITRATE).out

build:
	mkdir build
	mkdir build/sort
	mkdir build/titrate
	mkdir build/tools
	mkdir build/tools/instructions

build/%.o: src/%.c $(HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

build/titrate/%.o: src/titrate/%.c $(HEADER) $(TITRATE_HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	make -C $(LIBFT) clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)
	rm -rf $(TITRATE)
	rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re libft