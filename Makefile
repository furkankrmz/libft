
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akirmizi <42istanbul.com.tr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 11:05:52 by akirmizi          #+#    #+#              #
#    Updated: 2022/01/13 22:17:48 by akirmizi         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_memset.c			\
		ft_strnstr.c		\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c 		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strlen.c			\
		ft_isalpha.c 		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putnbr_fd.c		\
		ft_putendl_fd.c		\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_striteri.c		\
		ft_strmapi.c		\
		ft_itoa.c			\
		ft_strtrim.c		\
		ft_split.c			\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c 		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c


NAME = libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))


CC = clang

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Libft Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

