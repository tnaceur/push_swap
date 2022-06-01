NAME = push_swap
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = utils/ft_atoi.c\
	   utils/ft_lstlast.c\
	   utils/ft_lstadd_back.c\
	   utils/ft_lstnew.c\
	   utils/sorting_utils.c\
	   utils/sorting_utils2.c\
	   instructions/pa.c\
	   instructions/pb.c\
	   instructions/ra.c\
	   instructions/rb.c\
	   instructions/rr.c\
	   instructions/rra.c\
	   instructions/rrb.c\
	   instructions/rrr.c\
	   instructions/sa.c\
	   instructions/sb.c\
	   instructions/ss.c\
	   push_swap.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : 
		 $(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean : 
		$(RM) $(OBJS)
fclean : clean
		$(RM) $(NAME)
re : fclean all