.PHONY: all clean fclean re

NAME = libasm.a

SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJ = $(SRC:.s=.o)

FLAGS = -fmacho64

%.o: %.s
	nasm $(FLAGS) $<

all: $(NAME)

$(NAME): $(OBJ) main.c
	ar rcs $(NAME) $^

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all