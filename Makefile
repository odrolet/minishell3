NAME = minishell
CC = gcc
CFLAGS = -Werror -Wall -Wextra 

LDFLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
CPPFLAGS = -I${HOME}/.brew/opt/readline/include

INCLUDE_DIR	=	./include

SRCS = src/init.c src/libft_shit.c src/main.c src/minishell.c src/data_minishell.c src/process_loop.c

#src/garbage.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean :
	@rm -rf $(OBJS)

debug : fclean $(OBJS)
	$(CC) $(CFLAGS) -g -fsanitize=thread $(LDFLAGS) $(OBJS) -o $(NAME)


fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

#requiert l'installation de ->brew install readline et de ->brew link --force readline