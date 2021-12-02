NAME =      so_long
HEADER = so_long.h
LIST =     	so_long.c\
			so_long_utils.c\
			get_next_line/get_next_line.c\
		 	get_next_line/get_next_line_utils.c\
			graphics/graphis_map.c\
			graphics/graph_one.c\
			graphics/graph_utils.c\
			parser/pars_arr.c\
			parser/pars_map.c\

LIST_B = 	 bonus/graph_one_bonus.c\
			 bonus/graph_utils_bonus.c\
			 bonus/graph_map_bonus.c\
			 bonus/pars_arr_bonus.c\
			 bonus/pars_map_bonus.c\
			 bonus/so_long_bonus.c\
			 bonus/so_long_ut_bonus.c\
			 get_next_line/get_next_line.c\
             get_next_line/get_next_line_utils.c\

MINILIBX = libmlx.a

OBJ = $(patsubst %.c,%.o,$(LIST))

OBJ_B = $(patsubst %.c,%.o,$(LIST_B))

FLAGS = -Wall -Wextra -Werror -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

all :	$(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@make -C mlx
	@cp mlx/$(MINILIBX) .
	gcc $(FLAGS) $(LIST) -o $(NAME)

bonus : $(OBJ_B) $(HEADER)
	@make -C mlx
	@cp mlx/$(MINILIBX) .
	@make OBG="$(OBJ_B)" LIST="$(LIST_B)"

clean :
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C mlx
fclean : clean
	@rm -f $(NAME)
	@rm -f $(MINILIBX)

re :	fclean all
.PHONY : all clean fclean re bonus