
NAME	= push_swap
TITRATE	= titrate
ELUCIDATE	= elucidate

CFLAGS	= -Wall -Wextra -Werror -O3 -march=native -g
CC		= cc
ARCHIVE = ar -rcs

LIBFT_DIR	= ./libft

LINKERS	= -lm

LIBFT	= $(LIBFT_DIR)/build/libft.a

INCLUDE_DIRS = -I $(LIBFT_DIR)/include -I include

HEADER = include/push_swap.h
TITRATE_HEADER = include/titrate.h
ELUCIDATE_HEADER = include/elucidate.h

FILES := \
	elucidate/dpplist.c \
	elucidate/elucidate.c \
	elucidate/interpret_result.c \
	elucidate/investigate.c \
	elucidate/test_cycle.c \
	sort/council_sort.c \
	sort/main.c \
	sort/specialists.c \
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
	tools/inquisition/fools.c \
	tools/inquisition/inquisition.c \
	tools/panel.c \
	tools/read_stack.c \
	tools/normalize_stack.c

OBJECTS := $(FILES:.c=.o)

FILES := $(patsubst %.c, src/%.c, $(FILES))
OBJECTS := $(patsubst %.o, build/%.o, $(OBJECTS))

ELUCIDATE_OBJ := $(filter build/elucidate/%, $(OBJECTS))
SORT_OBJ := $(filter build/sort/%, $(OBJECTS))
TITRATE_OBJ := $(filter build/titrate/%, $(OBJECTS))
TOOLS_OBJ := $(filter build/tools/%, $(OBJECTS))

all: $(NAME)

bonus: all

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(NAME): $(LIBFT) build $(SORT_OBJ) $(TOOLS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SORT_OBJ) $(TOOLS_OBJ) $(LIBFT) $(LINKERS) -o $(NAME)

$(TITRATE): $(LIBFT) build $(TITRATE_OBJ) $(TOOLS_OBJ) $(HEADER) $(TITRATE_HEADER)
	$(CC) $(CFLAGS) $(TITRATE_OBJ) $(TOOLS_OBJ) $(LIBFT) $(LINKERS) -o $(TITRATE).out

$(ELUCIDATE): $(LIBFT) build $(ELUCIDATE_OBJ) $(TOOLS_OBJ) $(HEADER) $(ELUCIDATE_HEADER)
	$(CC) $(CFLAGS) $(ELUCIDATE_OBJ) $(TOOLS_OBJ) $(LIBFT) $(LINKERS) -o $(ELUCIDATE).out

build:
	mkdir build
	mkdir build/elucidate
	mkdir build/sort
	mkdir build/titrate
	mkdir build/tools
	mkdir build/tools/instructions
	mkdir build/tools/inquisition

build/%.o: src/%.c $(HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

build/titrate/%.o: src/titrate/%.c $(HEADER) $(TITRATE_HEADER)
	$(CC) -c $(INCLUDE_DIRS) $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf $(TITRATE)
	rm -rf build

re: fclean all

re: fclean all

.PHONY: all bonus clean fclean re