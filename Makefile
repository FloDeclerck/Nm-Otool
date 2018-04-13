# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 11:10:38 by fdeclerc          #+#    #+#              #
#    Updated: 2018/04/13 11:44:37 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM =	ft_nm

CC = 		gcc -Wall -Wextra -Werror

LFLAGS = 	-fPIC

LFT =		libft/

LIBS =		-L$(LFT) -lft

SRC =		./nm/sources/main.c\
			./nm/sources/nm.c\
			./nm/sources/sections.c\
			./nm/sources/swap.c\
			./nm/sources/symbols.c\
			./nm/sources/handle64.c\

RM =		rm -rf

OBJ =		$(SRC:.c=.o)

OBJDIR = 	obj

all:		$(NAME_NM)

$(NAME_NM):	$(OBJ)
			@make -C $(LFT)
			@echo "\033[32m[BUILDING $(NAME_NM)] \033[0m" | tr -d '\n'
			@$(CC) $(LFLAGS) -o $(NAME_NM) $(OBJ) $(LIBS)
			mkdir -p $(OBJDIR) && mv $(OBJ) ./$(OBJDIR)/
			@echo "\033[32m[$(NAME_NM) IS READY !]\033[0m"

%.o:		%.c
			@echo "\033[36m[COMPILING...]\033[0m" | tr -d '\n'
			$(CC) -o $@ -c $<

clean:
			@echo "\033[31m[CLEANING SOURCES] \033[0m" | tr -d '\n'
			$(RM) $(OBJDIR)
			@make clean -C libft

fclean:		clean
			@echo "\033[31m[FCLEAN $(NAME_NM)] \033[0m" | tr -d '\n'
			$(RM) $(NAME_NM)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean
