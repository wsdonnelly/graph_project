NAME = graph_project
CC = g++
CFLAGS = --std=c++11 -Wall
SRCS = sources/main.cpp sources/graph.cpp sources/kruskalMST.cpp
OBJS = main.o graph.o kruskalMST.o
INCLUDES = -I includes/

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

clean:
	rm -f *.o
	rm -f *.gch

fclean: clean
	rm $(NAME)

re: fclean all