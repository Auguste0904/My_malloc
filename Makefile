##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	=	libmy_malloc.so

CC		=	gcc

SRC		=	src/my_malloc.c			\
			src/my_free.c			\
			src/my_calloc.c			\
			src/my_realloc.c		\
			src/my_reallocarray.c


OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-I./include

LDFLAGS 	=	-Wall -Wextra -W -Werror

LFLAGS		=	-shared -fpic

all:	$(NAME)

%.o:	%.c
			@$(CC) $(CFLAGS) $(LFLAGS) -c -o $@ $<
			@echo -e "\033[0;32m[OK]    \033[1;32m" $< "\033[0m"

$(NAME):	$(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)
			@echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\033[1;33m\n"
			@echo -e " ███╗   ███╗██╗   ██╗     ███╗   ███╗ █████╗ ██╗     ██╗      ██████╗  ██████╗"
			@echo -e " ████╗ ████║╚██╗ ██╔╝     ████╗ ████║██╔══██╗██║     ██║     ██╔═══██╗██╔════╝"
			@echo -e " ██╔████╔██║ ╚████╔╝      ██╔████╔██║███████║██║     ██║     ██║   ██║██║     "
			@echo -e " ██║╚██╔╝██║  ╚██╔╝       ██║╚██╔╝██║██╔══██║██║     ██║     ██║   ██║██║     "
			@echo -e " ██║ ╚═╝ ██║   ██║███████╗██║ ╚═╝ ██║██║  ██║███████╗███████╗╚██████╔╝╚██████╗"
			@echo -e " ╚═╝     ╚═╝   ╚═╝╚══════╝╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚═════╝  ╚═════╝\033[0m"

run:	re
			@./$(NAME)

debug:	fclean $(OBJ)
			@echo -e "\033[0;34m[OK]     \033[1;34mObj's files successfully compiled!\033[0m"
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS) $(LDFLAGS)
			@echo -e "\033[0;34m[OK]    \033[1;34m" $(NAME) "successfully created!\033[0m\n"

clean:
			@rm -f $(OBJ)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs successfully cleaned!\033[0m"

fclean:	clean
			@rm -f $(shell find . -name "*~")
			@rm -f $(shell find . -name "a.out")
			@rm -f $(shell find . -name "vgcore.*")
			@rm -f $(shell find . -name "\#*#")
			@rm -f $(shell find . -name "*.gc*")
			@rm -f $(shell find . -name ".safe")
			@rm -f $(NAME)
			@echo -e "\033[0;33m[OK]     \033[1;33mOBJs and useless files successfully cleaned!\033[0m"

re:	fclean all

.PHONY:	all	clean	fclean	re	debug	run
