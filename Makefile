SRCS_CHECKER	=	checker_42/checker.c			\
					checker_42/init_values.c		\
					checker_42/check_operations.c	\
					checker_42/operations.c

OBJS_CHECKER	= $(SRCS_CHECKER:.c=.o)

NAME_CHECKER	= checker

SRCS_PUSH_SWAP	=	push_swap_42/push_swap.c		\
					push_swap_42/init_values.c		\
					push_swap_42/utils.c			\
					push_swap_42/algorithm.c		\
					push_swap_42/algorithm_sort.c	\
					push_swap_42/operations.c

OBJS_PUSH_SWAP	= $(SRCS_PUSH_SWAP:.c=.o)

NAME_PUSH_SWAP	= push_swap

FLAGS			= -Wall -Werror -Wextra

RM				= rm -f

.c.o:
			@gcc -c $< -o $(<:.c=.o)

$(NAME_CHECKER):	$(OBJS_CHECKER) $(NAME_PUSH_SWAP) _libft
					@gcc -o $(NAME_CHECKER) $(OBJS_CHECKER) $(shell find libft/ -name "*.a")

$(NAME_PUSH_SWAP):	$(OBJS_PUSH_SWAP) _libft
					@gcc -o $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) $(shell find libft/ -name "*.a")

all:		$(NAME_CHECKER)

clean:
			$(RM) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean:		clean
			$(RM) $(NAME_CHECKER) $(NAME_PUSH_SWAP)
			@make fclean -C libft

re:			fclean all

_libft:
			@make -C libft

Norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS)

.PHONY:		all clean fclean re bonus Norme checker push_swap
