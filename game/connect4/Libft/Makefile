SRCS = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_strndup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strnlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
ft_strjoin2.c\
ft_strcmp.c\
ft_strstr.c

BONUS_SRCS = ft_lstnew.c\
ft_lstadd_front.c\
ft_lstsize.c\
ft_lstlast.c\
ft_lstadd_back.c\
ft_lstdelone.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c\
get_next_line.c\
sget_next_line.c\
ft_isatoiable.c\
ft_satoi.c

HEADER = libft.h
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
NAME = libft.a

CC = cc
CFLAGS= -Wall -Wextra -Werror

ifeq (${MAKECMDGOALS}, bonus)
SRCS += ${BONUS_SRCS}
OBJS = ${SRCS:.c=.o}
endif

all : ${NAME}

bonus : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	ar -rc ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< 

clean :
	rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	rm -f ${NAME}

re	: fclean all

.PHONY : all bonus clean fclean re
