#ifndef KRUSKAL_MST_HPP
#define KRUSKAL_MST_HPP

#include <vector>
#include <queue>
#include "edges.hpp"
#include "graph.hpp"

//assume undirected graph with positive non zero weights
class KruskalMST {
	private:
	//variables
		int total_cost = 0;
		std::vector<int> node_set;
		std::vector<Edges> edge_list;
		std::priority_queue <Edges, std::vector<Edges>, std::greater<Edges>> p_queue;
	//helper functions
		void combine_sets(const int setA, const int setB);
		bool is_connected();
	public:
		KruskalMST(Graph &graph);
		void get_MST();
		void get_cost();
		void get_edge_set();
};

#endif