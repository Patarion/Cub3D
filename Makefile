NAME = cub3d

LIBFT_DIR = inc/Libft/
LIBFT = ${MAKE} --silent -C ${LIBFT_DIR}

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

OBJS = $(SRCS:.c=.o)

CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
NORM = norminette
RM = rm -rf

all: $(NAME)

$(OBJS_DIR)%.o:%.c
	@${CC} ${CFLAGS} -I${LIBFT_DIR} -o $@ -c $<

$(NAME):
		${LIBFT}
		${CC} ${CFLAGS} ${SRCS} -L${LIBFT_DIR} -lft -o ${NAME}
#		@mv ${SRCS_DIR}*.o ${OBJS_DIR}
		@echo "____Cub3D créé avec succès____"

clean:
		${RM} ${NAME} ${NAME}.dSYM
		${RM} ${OBJS_DIR}/*.o
		@echo "____L'exécutable a été supprimé____"
fclean: clean

re: fclean all

.PHONY: all clean fclean re