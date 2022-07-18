#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>

class Graph
{
private:
	std::vector<std::vector<int[2]>> adjacenyList_;
	int E_;
	int V_;
public:
	Graph();
	bool isEmpty();
	void insertVertex(int v);
	void insertEdge(int v1, int v2, int w);
	void adjacent(int v);
};

#endif // !_GRAPH_H_
