#ifndef EDGES_HPP
#define EDGES_HPP

#include <iostream>

struct Edges {
	int v1;
	int v2;
	int cost;
	//functor for 'cost' comparison
	bool operator>(const Edges &rhs) const
	{
		return cost > rhs.cost;
	}
};

//overload << struct Edges
inline std::ostream &operator<<(std::ostream &out_stream, const Edges &edge) {
	out_stream << "(" << edge.v1 << ", " <<edge.v2 << ", " << edge.cost << ")";
	return (out_stream);
}

#endif