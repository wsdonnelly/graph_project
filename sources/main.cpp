#include "graph.hpp"
#include "kruskalMST.hpp"

/*
** graph can either read from a file (assumes no errors and should be exact format as example file)
** graph can also be randomly generated
** included at bottom of this file is the complete example graph, copy it to a file in your root and call it 'example.graph'
*/

int main() {

	//read from file
	//Graph mygraph("example.graph");

	//create 'random graph'
	Graph mygraph(20, 0.4, 10);

	mygraph.print_matrix();
	std::cout << "\n";
	KruskalMST mst(mygraph);
	mst.get_MST();
	mst.get_cost();
	mst.get_edge_set();
	return (0);
}
