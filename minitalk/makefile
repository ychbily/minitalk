NAME = server client

bonus = server_bonus client_bonus

SRC = utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
bonus : $(bonus) 

server : server.c $(SRC) minitalk.h
	cc $(CFLAGS) $< $(SRC) -o $@

client : client.c $(SRC) minitalk.h
	cc $(CFLAGS) $< $(SRC) -o $@

server_bonus : server_bonus.c $(SRC) minitalk.h
	cc $(CFLAGS) $< $(SRC) -o $@

client_bonus : client_bonus.c $(SRC) minitalk.h
	cc $(CFLAGS) $< $(SRC) -o $@ 

clean : 
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME) $(bonus)

re : fclean all