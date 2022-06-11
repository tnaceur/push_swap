NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = push_swap.c\
	   utils/ft_atoi.c\
	   utils/ft_lstlast.c\
	   utils/ft_lstadd_back.c\
	   utils/ft_lstnew.c\
	   utils/sorting_utils.c\
	   utils/sorting_utils2.c\
	   utils/sorting_utils3.c\
	   utils/sorting_utils4.c\
	   utils/sorting_utils5.c\
	   utils/ft_lstsize.c\
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

SRCS_B = bonus/checker.c\
         utils/ft_atoi.c\
		 bonus/get_next_line.c\
		 utils/ft_lstlast.c\
		 utils/ft_lstadd_back.c\
		 utils/ft_lstnew.c\
		 utils/sorting_utils.c\
		 utils/sorting_utils2.c\
		 utils/sorting_utils3.c\
		 utils/sorting_utils4.c\
		 utils/sorting_utils5.c\
		 utils/ft_lstsize.c\
		 instructions_b/pa.c\
		 instructions_b/pb.c\
		 instructions_b/ra.c\
		 instructions_b/rb.c\
		 instructions_b/rr.c\
		 instructions_b/rra.c\
		 instructions_b/rrb.c\
		 instructions_b/rrr.c\
		 instructions_b/sa.c\
		 instructions_b/sb.c\
		 instructions_b/ss.c\

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		 $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus :   $(OBJS_B)
		$(CC) $(CFLAGS) $(OBJS_B) -o $(BONUS)

clean :
		$(RM) $(OBJS) $(OBJS_B)
fclean : clean
		$(RM) $(NAME) $(BONUS)
re : fclean all