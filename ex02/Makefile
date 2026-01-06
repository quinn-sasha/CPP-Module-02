TARGET := a.out

CC := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRCS := main.cpp \
				Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

test_memory_leak: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=reachable --track-origins=yes ./$(TARGET) "WARNING"

re: fclean all

.PHONY: all clean fclean re test_memory_leak
