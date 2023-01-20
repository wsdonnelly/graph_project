#include "dijkstra.hpp"
#include <iostream>
#include <utility>
#include <queue>
#include <iomanip>

DijkstraSPT::DijkstraSPT(Graph &graph, int start): size(graph.size), origin(start), dist(size, INT_MAX), prev(size, -1) { //enter origin 
	using int_pair = std::pair<int, int>;
	std::priority_queue <int_pair, std::vector<int_pair>, std::greater<int_pair>> p_queue;

	dist[origin] = 0;
	p_queue.push(std::make_pair(dist[origin], origin));
	
	while (!p_queue.empty()) {
		int cur_vertex = p_queue.top().second; //vertex with shortest distance from origin
		p_queue.pop();
		//loop through neighbors
		for (int v = 0; v < size; v++) {
			if (graph.matrix[cur_vertex][v]) { //if a neighbor exists
				int alt = dist[cur_vertex] + graph.matrix[cur_vertex][v];
				if (alt < dist[v]) {
					dist[v] = alt;
					prev[v] = cur_vertex;
					p_queue.push(std::make_pair(dist[v], v));
				}
			}
		}
	}
}

void DijkstraSPT::print_SPT() {
	std::cout << "Dijkstra Smallest Path Tree\n";
	std::cout << "(vertex, distance, previous)\n";
	for (int i = 0; i < size; i++) {
		int x = (i + origin) % size;
		std::cout << std::setw(2) << x << " " << std::setw(2) << dist[x] << " " << std::setw(2) << prev[x] << std::endl;
	}

}

/*
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5
6      for each vertex v in Graph.Vertices:
7          if v ≠ source
8              dist[v] ← INFINITY                 // Unknown distance from source to v
9              prev[v] ← UNDEFINED                // Predecessor of v
10
11         Q.add_with_priority(v, dist[v])
12
13
14     while Q is not empty:                      // The main loop
15         u ← Q.extract_min()                    // Remove and return best vertex
16         for each neighbor v of u:              // Go through all v neighbors of u
17             alt ← dist[u] + Graph.Edges(u, v)
18             if alt < dist[v]:
19                 dist[v] ← alt
20                 prev[v] ← u
21                 Q.decrease_priority(v, alt)
22
23     return dist, prev
*/