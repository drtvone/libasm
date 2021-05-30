SRCS		=	ft_strlen.s \
				ft_strcmp.s \
				ft_strdup.s \
				ft_write.s \
				ft_strcpy.s \
				ft_read.s

OBJS		=	$(SRCS:.s=.o)

FLAGS 		=	-Wall -Werror -Wextra
NAME		=	libasm.a
TEST		=	test

%.o:%.s
				nasm -f macho64 $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
				./$(TEST) < Makefile


.PHONY:			clean fclean re test