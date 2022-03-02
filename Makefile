NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER =	\
			./includes/pipex.h		\

BONUS =		\
			./bonus/pipex_bonus.c	\

PARSING =	\
			./parsing/check_files.c	\
			./parsing/parsinit.c	\

ADD =	\
		./add/free.c				\
		./add/err.c					\
		./add/flags.c				\
		./add/utils.c				\

INIT =	\
		./init/get_paths.c			\
		./init/init_struct.c		\

SRCS =	\
		./srcs/main.c				\
		${PARSING}					\
		${INIT}						\
		${ADD}						\
		#./srcs/pipex.c				\

OBJS = ${SRCS:.c=.o}
OBJS_BON = ${BONUS:.c=.o}

LIB = ./libft/libft.a

all :	library ${NAME}

library :
	make -C ./libft

%.o :	%.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

${NAME} :	${OBJS} ${LIB}
	${CC} ${OBJS} ${LIB} -o ${NAME}

bonus :		${NAME} 
clean :
	make -C ./libft clean
	/bin/rm -f ${OBJS}

fclean :	clean
	/bin/rm -f libft/libft.a
	/bin/rm -f ${NAME}

re :	fclean all

.PHONY :	all library clean fclean re
