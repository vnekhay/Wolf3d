NAME = wolf3d

SRC= 	src/actions.c \
        src/additions.c \
        src/draw_floor_ceiling.c \
        src/key_hooks.c \
        src/moves.c \
        src/raycasting.c \
        src/read_map.c \
        src/rotations.c \
        src/wolfstart.c \

OBJECT = $(SRC:.c=.o)

HEADER = inc

all: $(NAME)

$(NAME): $(OBJECT)
	make -C libft/
	gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJECT) -Iinc -Llibft -lft -o $(NAME)

%.o:%.c $(HEADER)
	gcc -Wall -Wextra -Werror -o $@ -c $< -Iinc

clean:
	make -C libft/ clean
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all