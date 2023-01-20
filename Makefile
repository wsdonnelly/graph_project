NAME =		graph_project
CC =		g++
CFLAGS =	--std=c++11 -Wall
SRCS =		sources/main.cpp sources/graph.cpp sources/kruskalMST.cpp sources/dijkstra.cpp
OBJS =		main.o graph.o kruskalMST.o dijkstra.o
INCLUDES =	-I includes/
HEADERS =		includes/dijkstra.hpp includes/edges.hpp includes/graph.hpp includes/kruskalMST.hpp 

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

$(OBJS): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

clean:
	rm -f *.o
	rm -f *.gch

fclean: clean
	rm $(NAME)

re: fclean all