#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>

class Graph
{
private:
	std::vector<std::vector<int[2]>> adjacenyList_;
public:
	Graph() = default;
	void insert(int v1, int v2, int w);

};

#endif // !_GRAPH_H_
