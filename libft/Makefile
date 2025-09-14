NAME      := libft.a

SRC_FILES := \
	ft_atoi.c \
	ft_atol.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isprint.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_isdigit.c \
	ft_isascii.c \



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
	cc $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES) .bonus_stamp

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
