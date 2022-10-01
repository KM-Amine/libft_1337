NAME = libft.a
CC = gcc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -I .
RM = rm -rf

SRC = $(filter-out ft_ls%.c , $(wildcard ft_*.c))
BSRC = $(filter ft_ls%.c , $(wildcard ft_*.c))


OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all: $(NAME)

bonus: all $(BOBJ)
	@$(AR) $(NAME) $(BOBJ)
	@echo ---bonus generated----

$(NAME):$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo ---library generated----

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo ---objects cleaned----
fclean: clean
	@$(RM) $(NAME)
	@echo ---library cleaned----
re: fclean all

.PHONY: all clean fclean re bonus