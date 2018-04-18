# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 11:10:38 by fdeclerc          #+#    #+#              #
#    Updated: 2018/04/18 12:56:25 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM =	ft_nm
NAME_OT =	ft_otool

CC = 		gcc -Wall -Wextra -Werror

LFLAGS = 	-fPIC

LFT =		libft/

LIBS =		-L$(LFT) -lft -lm

SRC_NM =	./nm/sources/main.c\
			./nm/sources/nm.c\
			./nm/sources/handle64.c\
			./nm/sources/handle32.c\
			./nm/sources/fat.c\
			./nm/sources/sections.c\
			./nm/sources/swap.c\
			./nm/sources/symbols.c\


SRC_OT =	./otool/sources/main.c\
			./otool/sources/otool.c\
			./otool/sources/handle64.c\
			./otool/sources/handle32.c\
			./otool/sources/section.c\
			./nm/sources/sections.c\
			./nm/sources/swap.c\
			./nm/sources/symbols.c\

OBJ_NM =		$(SRC_NM:%.c=%.o)
OBJ_OT = 		$(SRC_OT:%.c=%.o)

LIBFT =			libft/libft.a

RM =		rm -rf

all:		$(NAME_NM) $(NAME_OT)

$(LIBFT):
	@echo "COMPILING LIBFT..."
	@make -C libft/
	@echo "Done"

$(NAME_NM): $(LIBFT) $(OBJ_NM)
			@echo "\033[32m[BUILDING $(NAME_NM)] \033[0m" | tr -d '\n'
			@$(CC) $(LFLAGS) -o $(NAME_NM) $(OBJ_NM) $(LIBS)
			@echo "\033[32m[$(NAME_NM) IS READY !]\033[0m"

$(NAME_OT): $(LIBFT) $(OBJ_OT)
			@echo "\033[32m[BUILDING $(NAME_OT)] \033[0m" | tr -d '\n'
			@$(CC) $(LFLAGS) -o $(NAME_OT) $(OBJ_OT) $(LIBS)
			@echo "\033[32m[$(NAME_OT) IS READY !] \033[0m"

%.o:		%.c
			@echo "\033[36m[COMPILING...]\033[0m" | tr -d '\n'
			$(CC) -o $@ -c $<

clean:
			@echo "\033[31m[CLEANING SOURCES] \033[0m" | tr -d '\n'
			$(RM) $(OBJ_NM) $(OBJ_OT)
			@make clean -C libft

fclean:		clean
			@echo "\033[31m[FCLEAN $(NAME_NM)] \033[0m" | tr -d '\n'
			@echo "\033[31m[FCLEAN $(NAME_OT)] \033[0m" | tr -d '\n'
			$(RM) $(NAME_NM) $(NAME_OT)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
