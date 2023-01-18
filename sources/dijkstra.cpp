#include "dijkstra.hpp"
#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
#include <iomanip>


DijkstraSPT::DijkstraSPT(Graph &graph, const int start): size(graph.size), origin(start), dist(size, INT_MAX), prev(size, -1) { //enter origin 
	using int_pair = std::pair<int, int>;
	std::priority_queue <int_pair, std::vector<int_pair>, std::greater<int_pair>> p_queue;

	dist[origin] = 0;
	p_queue.push(std::make_pair(dist[origin], origin));
	
	while (!p_queue.empty()) {
		int cur_vertex = p_queue.top().second; //vertex with shortest distance from origin
		p_queue.pop();
		//loop through neighbors
		for (int v = 0; v < size; v++) {
			if (graph.matrix[cur_vertex][v]) { 
				int new_dist = dist[cur_vertex] + graph.matrix[cur_vertex][v];
				if (new_dist < dist[v]) {
					dist[v] = new_dist;
					prev[v] = cur_vertex;
					p_queue.push(std::make_pair(dist[v], v));
				}
			}
		}
	}
}

void DijkstraSPT::print_SPT() {
	std::cout << "shortest path tree from origin: " << origin << std::endl;
	std::cout << "(vertex, distance, previous)\n";
	for (int i = 0; i < size; i++) {
		int x = (i + origin) % size;
		std::cout << std::setw(2) << x << " " << std::setw(2) << dist[x] << " ";
		std::cout << std::setw(2) << prev[x] << std::endl;
	}

}
