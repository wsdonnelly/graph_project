#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>

//create a graph randomly, or by reading a file
//if from file assumes no errors in input

class Graph {
	private:
		int size;
		double density;
		int distance = 10;
		const std::string file_path;
		std::vector<std::vector<int>> matrix;
		void add_edge(int i, int j, int w);
		void create_new();
		friend class KruskalMST;
		friend class DijkstraSPT;
	public:
		//construct from file path
		Graph(std::string file_path);
		//make random 
		Graph(int size = 50, double density = 0.2, int distance = 10);
		void print_matrix();
};

#endif