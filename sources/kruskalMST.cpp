#include "kruskalMST.hpp"

KruskalMST::KruskalMST(Graph &graph) {
	//create vector to keep track of which tree a node belongs to
	node_set.resize(graph.size, 0);
	
	//create edge list in the form (i, j, w)and add to min heap priority queue
	//loop through diagonal of matrix 
	for(int i = 1; i < graph.size; i++) {
		for (int j = 0; j < i; j++) {
			if (graph.matrix[i][j]) {
				p_queue.push(Edges{i, j, graph.matrix[i][j]});
			}
		}
	}
}

void KruskalMST::get_MST() {
	int set = 1;
	while (!p_queue.empty() && edge_list.size() != node_set.size() - 1) {
		Edges const &edge = p_queue.top();
		//both nodes not in any set
		if (!node_set[edge.v1] && !node_set[edge.v2]) { 
			node_set[edge.v1] = set;
			node_set[edge.v2] = set;
			edge_list.push_back(edge);
			set++;
		}
		//node1 in a set and node2 not
		else if (node_set[edge.v1] && !node_set[edge.v2]) {
			node_set[edge.v2] = node_set[edge.v1];
			edge_list.push_back(edge);
		}
		//node1 not in a set and node2 in a set
		else if (!node_set[edge.v1] && node_set[edge.v2]) {
			node_set[edge.v1] = node_set[edge.v2];
			edge_list.push_back(edge);
		}
		//node1 in a set and node2 in a different set
		else if (node_set[edge.v1] != node_set[edge.v2]) {
			combine_sets(node_set[edge.v1], node_set[edge.v2]);
			edge_list.push_back(edge);
		}
		//node1 and node2 in the same set can be skiped
		p_queue.pop();

	}
	if (!is_connected()) {
		std::cout << "Graph is diconnected try making another" << std::endl;
		exit(1);
	}
}

void KruskalMST::combine_sets(const int setA, const int setB) {
	for (auto &it : node_set)
		if (it == setB)
			it = setA;
}

//checks if randomly generated graph is connected
bool KruskalMST::is_connected() {
	int val = node_set.at(0);
	for (auto i : node_set)
		if (i != val)
			return (false);
	return (true);
}

void KruskalMST::get_cost() {
	for (auto edge : edge_list)
		total_cost += edge.cost;
	std::cout << "Total MST Cost: " << total_cost <<std::endl;
}

void KruskalMST::get_edge_set() {
	std::cout << "MST edge list (vertex 1, vertex 2, cost)\n";
	for (auto edge : edge_list)
		std::cout << edge << std::endl; //overloaded << for type Edges
}
