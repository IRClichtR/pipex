NAME		= pipex

PRINTF_SRC	= $(addprefix ft_printf/, arg_hex.c arg_ptr.c arg_uint.c ft_nbrsize.c \
arg_char.c arg_int.c arg_str.c ft_hexasize.c ft_printf.c)

LIBFT_SRC	= $(addprefix ft_printf/libft/, \
ft_itoa.c         ft_lstsize.c      ft_putstr_fd.c    ft_strmapi.c \
ft_atoi.c         ft_lstadd_back.c  ft_memchr.c       ft_split.c        ft_strncmp.c \
ft_bzero.c        ft_lstadd_front.c ft_memcmp.c       ft_strchr.c       ft_strnstr.c \
ft_calloc.c       ft_lstclear.c     ft_memcpy.c       ft_strdup.c       ft_strrchr.c \
ft_isalnum.c      ft_lstdelone.c    ft_memmove.c      ft_striteri.c     ft_strtrim.c \
ft_isalpha.c      ft_lstiter.c      ft_memset.c       ft_strjoin.c      ft_substr.c \
ft_isascii.c      ft_lstlast.c      ft_putchar_fd.c   ft_strlcat.c      ft_tolower.c \
ft_isdigit.c      ft_lstmap.c       ft_putendl_fd.c   ft_strlcpy.c      ft_toupper.c \
ft_isprint.c      ft_lstnew.c       ft_putnbr_fd.c    ft_strlen.c)

LIBTL_SRC	= $(addprefix libtools/, \
dump_add.c     dump_del.c     get_len.c      super_strdup.c)

PIPEX_SRC	= $(addprefix pipex_dir/, \
copy_path.c   main.c        pipex.c       redirection.c \
execution.c   open_file.c   split_path.c)

SRCS		= $(GNL_SRC) $(PRINTF_SRC) $(LIBFT_SRC) $(LIBTL_SRC) $(PIPEX_SRC)

OBJS_DIR	= OBJS
OBJS		= $(addprefix $(OBJS_DIR)/, $(patsubst %.c, %.o, $(notdir $(SRCS))))

CC			= cc
CFLAGS		= -g -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: */%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
clean: 
	rm -rf $(OBJS_DIR)
fclean: clean
	rm -f $(NAME)
.PHONY: all clean fclean re
