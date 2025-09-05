NAME      := libft.a

SRC_FILES := \
	ft_atoi.c \
	ft_calloc.c \
	...（略）... \
	ft_tolower.c \
	ft_isdigit.c \
	ft_isascii.c


FTPRINTF_SRC := \
	ft_printf/ft_printf.c \
	ft_printf/ft_spec_char.c \
	ft_printf/ft_spec_hex.c \
	ft_printf/ft_spec_num.c \
	ft_printf/ft_spec_string_ptr.c

SRC_FILES += $(FTPRINTF_SRC)

OBJ_FILES := $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES := \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
BONUS_OBJ_FILES := $(BONUS_OBJ_FILES:.c=.o)

CFLAGS := -Wall -Wextra -Werror
INCS   := -I . -I ft_printf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

bonus: .bonus_stamp

.bonus_stamp: $(OBJ_FILES) $(BONUS_OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	@touch .bonus_stamp

%.o: %.c
	cc $(CFLAGS) $(INCS) -c $< -o $@   # ★$(INCS) を追加

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES) .bonus_stamp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
