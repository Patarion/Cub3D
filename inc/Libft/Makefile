# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgagnon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 12:49:23 by jgagnon           #+#    #+#              #
#    Updated: 2021/10/27 14:02:40 by jgagnon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

FLAGS = -g -Wall -Wextra -Werror

SRCS_FILES = 	ft_atoi.c\
			 	ft_bzero.c\
			 	ft_calloc.c\
			 	ft_isalnum.c\
			 	ft_isalpha.c\
			 	ft_isascii.c\
			 	ft_isdigit.c\
			 	ft_isprint.c\
			 	ft_memchr.c\
			 	ft_memcmp.c\
			 	ft_memcpy.c\
			 	ft_memmove.c\
			 	ft_memset.c\
			 	ft_strchr.c\
			 	ft_strdup.c\
			 	ft_strlcat.c\
			 	ft_strlcpy.c\
			 	ft_strlen.c\
			 	ft_strncmp.c\
			 	ft_strnstr.c\
			 	ft_strrchr.c\
			 	ft_tolower.c\
				ft_toupper.c\
			 	ft_substr.c\
			 	ft_strjoin.c\
			 	ft_strtrim.c\
			 	ft_split.c\
			 	ft_itoa.c\
			 	ft_strmapi.c\
			 	ft_striteri.c\
			 	ft_putchar_fd.c\
			 	ft_putstr_fd.c\
			 	ft_putendl_fd.c\
			 	ft_putnbr_fd.c\
				ft_findreturn.c\
				ft_bufbeg.c\
				get_next_line.c\
				ft_buffconcatenate.c\
				xfree.c\
				ft_strjoinfree.c\
				ft_isspace.c\
				ft_charjoinfree.c\
				ft_charsetcmp.c



BONUS = 		ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\

OBJS_FILES = $(SRCS_FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

NORM = norminette

RM = rm -f

all: $(NAME)

$(NAME) :	$(OBJS_FILES)
			ar -rcs $(NAME) $(OBJS_FILES)
			@echo "____Libft.h créé avec succes____"

bonus: $(NAME) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)
	@echo "____Libft.h et les bonus ont été créés avec succès____"

clean:
	rm -rf $(OBJS_FILES) $(OBJS_BONUS)
	@echo "____Les objects des fonctions sont supprimes____"

fclean: clean
	rm -f $(NAME)
	@echo "____Les textes anciens sont brûlés____"

re: fclean all
