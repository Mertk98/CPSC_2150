#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Edge
{
private:
	int source_;
	int target_;
	int weight_;
	friend class Graph;
public:
	Edge(int source, int target, int weight);
};

class Graph
{
private:
	//sparse
	std::vector<std::vector<Edge*>> adjacencyList_;
	//dense
	std::vector<std::vector<int>> adjacencyMatrix_;
	int E_;
	int V_;
	// checking if the graph if directed
	bool directed_;
	// checking if dense
	bool dense_;
public:
	// default, creates a sparse graph
	Graph();
	// specify dense or sparse, directed or undirected
	Graph(int vertices, bool directed, bool dense);
	bool isEmpty();
	int totalEdges();
	int totalVertices();
	void createSparse();
	void createDense();
	void insertEdge(int v1, int v2, int w);
	void adjacent(int v);
	bool edgeExists(int v1, int v2);
	void printEdges(std::string fileName);
	~Graph();
};

#endif // !_GRAPH_H_
