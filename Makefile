NAME = cub3d

LIBFT_DIR = inc/Libft/
MLX_DIR = MLX42/
LIBFT = ${MAKE} --silent -C ${LIBFT_DIR}
MLX_MAKE = ${MAKE} --silent -C ${MLX_DIR}

OBJS_DIR = obj/
SRCS_DIR = src/


SRCS = 	src/main.c\
 		src/init_data.c\
 		src/utils.c\
 		src/parsing_info.c\
 		src/parsing_map.c\
 		src/clear.c\
 		src/get.c\
 		src/error.c\
		src/raycasting/raycast.c\
		src/raycasting/texture.c\
		src/cube/init_game.c\
		src/cube/key_event.c\

SRCS_TEST = test/main.c

OBJS = $(SRCS:.c=.o)

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
MLX = MLX42/libmlx42.a 
MLX_FLAG = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib
NORM = norminette
RM = rm -rf

all: $(NAME)

$(OBJS_DIR)%.o:%.c
	@${CC} ${CFLAGS} -I${LIBFT_DIR} -o $@ -c $<

$(NAME):
		${LIBFT}
		${MLX_MAKE}
		${CC} ${CFLAGS} ${SRCS} -L${LIBFT_DIR} -lft ${MLX} ${MLX_FLAG} -framework OpenGL -framework AppKit -o ${NAME}
#		@mv ${SRCS_DIR}*.o ${OBJS_DIR}
		@echo "____Cub3D créé avec succès____"

mlx:
		${LIBFT}
		${CC} ${CFLAGS} ${SRCS_TEST} -L${LIBFT_DIR} -lft ${MLX} ${MLX_FLAG} -framework OpenGL -framework AppKit -o mlx
# 		@mv ${SRCS_DIR}*.o ${OBJS_DIR}
		@echo "____Les fichiers tests ont été créés____"

clean:
		${RM} ${NAME} ${NAME}.dSYM
		${RM} mlx
		${RM} ${OBJS_DIR}*.o
		${RM} ${LIBFT_DIR}*.o
		${RM} ${LIBFT_DIR}*.a
		${RM} ${MLX_DIR}*.a
		@echo "____L'exécutable a été supprimé____"
fclean: clean

re: fclean all

.PHONY: all clean fclean re