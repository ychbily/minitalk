# EXECUTABLES
CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

NAME = $(CLIENT) $(SERVER)
NAME_BONUS = $(CLIENT_BONUS) $(SERVER_BONUS)

# SOURCE FILES
SERVER_SRC = utils.c server.c
CLIENT_SRC = utils.c client.c

SERVER_BONUS_SRC = utils.c server_bonus.c
CLIENT_BONUS_SRC = utils.c client_bonus.c

#OBJECT FILES
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

OBJS = $(SERVER_SRC:.c=.o) $(CLIENT_SRC:.c=.o)
BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o) $(CLIENT_BONUS_SRC:.c=.o)

# FLAGS
CFLAGS = -Wall -Wextra -Werror

##
COMPILATION_STARTED := .compilation_started
RM = rm -rf
##

# RULES
all : $(NAME)
	@rm -f $(COMPILATION_STARTED)
	@echo "\n(꩜ ᯅ ꩜;)⁭ ⁭⁭ 📦 All Done. 📦  (꩜ ᯅ ꩜;)⁭ ⁭\n⁭"

bonus : $(NAME_BONUS)
	@rm -f $(COMPILATION_STARTED)
	@echo "\n(꩜ ᯅ ꩜;)⁭ ⁭⁭ 📦 All Done. 📦  (꩜ ᯅ ꩜;)⁭ ⁭\n⁭"

%.o: %.c minitalk.h
	@if [ ! -f $(COMPILATION_STARTED) ]; then \
		echo "\nCompilation starting: "; \
		touch $(COMPILATION_STARTED); \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@ && printf "⌛"

$(NAME): $(OBJS)
	@echo "\n\n⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"
	@echo "⁺｡˚        Linking $@...        ｡⁺⋆"
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)
	@echo "⁺｡˚   Linking of $@ complete.   ｡⁺⋆"
	@echo "⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "\n\n⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"
	@echo "⁺｡˚        Linking $@...        ｡⁺⋆"
	@$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER_BONUS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT_BONUS)
	@echo "⁺｡˚   Linking of $@ complete.   ｡⁺⋆"
	@echo "⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆⋆⁺｡˚⋆˙‧₊☽ ◯ ☾₊‧˙⋆˚｡⁺⋆"

clean :
	@echo "Cleaning object files ..."
	@$(RM) $(OBJS) $(BONUS_OBJS) $(COMPILATION_STARTED)
	@echo "▄︻デ══━一💥 Clean complete. 💥一━══デ︻▄"

fclean: clean
	@echo "\n⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖⊹ ࣪ ﹏𓊝﹏𓂁﹏⊹ ࣪ ˖"
	@echo "\nRemoving binaries..."
	@$(RM) $(OBJS) $(BONUS_OBJS) $(NAME) $(NAME_BONUS)
	@echo "▄︻デ══━一💥 Full clean complete. 💥一━══デ︻▄"

re : fclean all

.PHONY: clean