# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagimeno <dagimeno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 15:00:33 by dagimeno          #+#    #+#              #
#    Updated: 2024/10/25 13:03:08 by dagimeno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_check_extention.c\
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
	ft_substr.c ft_tolower.c ft_toupper.c ft_printf.c ft_printf_utils.c\
	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c\
	get_next_line_bonus.c get_next_line_utils_bonus.c\
	get_next_line_bonus_p.c get_next_line_utils_bonus_p.c\
	ft_dprintf.c ft_dprintf_utils.c\
	ft_sprintf.c ft_sprintf_utils.c\
	ft_alloc.c ft_itoa_p.c ft_lstnew_bonus_p.c ft_split_p.c ft_strdup_p.c ft_strjoin_p.c\
	ft_strmapi_p.c ft_strtrim_p.c ft_substr_p.c

CFLAGS = -Wall -Wextra -Werror

CC = cc
  
OFILES = $(CFILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME):$(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
