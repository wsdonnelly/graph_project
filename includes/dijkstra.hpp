
#include <climits>
#include <vector>

#include "graph.hpp"

class DijkstraSPT {
	private:
		const int size;
		const int origin;
		std::vector<int> dist;
		std::vector<int> prev;
	public:
		DijkstraSPT(Graph &graph, const int start);
		void print_SPT();
};

