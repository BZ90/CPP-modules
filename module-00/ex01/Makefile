SRCS = main.cpp PhoneBook.cpp Contact.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

NAME = PhoneBook

RM = rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
