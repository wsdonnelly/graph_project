#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "graph.hpp"

//constructor from file
Graph::Graph(std::string file_path): file_path(file_path) {
	//open file, and create line variable
	std::ifstream graph_file(file_path);
	std::string line;

	//get first line (size)
	std::getline(graph_file, line);
	std::istringstream iss(line);
	iss >> this->size;
	//create matrix
	matrix.resize(size);
	for (int i = 0; i < (int)matrix.size(); i++)
		matrix.at(i).resize(size);
	//get edges
	while (std::getline(graph_file, line)) {
		std::istringstream iss(line);
		int i, j, w;
		//basic error check
		if (!(iss >> i >> j >> w)) {
			std::cout << "Error in edges" <<std::endl;
			break ;
		}
		add_edge(i, j, w);
	}
}

//Graph::Graph(int size = 50, double density = 0.2, int distance = 10)
Graph::Graph(int size, double density, int distance)
: size((size > 10000) ? 10000 : size), density(density), distance(distance) {
	//check if density and distance range are within the correct range
	if (density > 1.0 || density < 0.0) {
		std::cout << "density out of range, reverting to default (0.2)" << std::endl;
		density = 2.0;
	}
	if (distance > 10 || distance < 1) {
		std::cout << "distance out of range, reverting to default (10)" << std::endl;
		distance = 10;
	}
	this->create_new();
}

void Graph::print_matrix() {
	int num_digis = floor(log10(distance) + 1);
	int index = 0;
	std::cout << "Graph Adjacency Matrix\n";
	for (auto i : matrix) {
		std::cout << std::setw(num_digis) << (index++) << ": ";
		for (auto j : i)
			std::cout << std::setw(num_digis) << j << " ";
		std::cout << "\n";
	}
}

void Graph::add_edge(int i, int j, int w) { 
	matrix[i][j] = w;
}

void Graph::create_new() {
	matrix.resize(size);
	for (int i = 0; i < (int)matrix.size(); i++)
		matrix.at(i).resize(size);
	srand(time (0));
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (rand() % 100 < static_cast<int>(density * 100.0)) {
				int cost = rand() % distance + 1; 
				add_edge(i, j, cost);
				add_edge(j, i, cost);
			}
}
