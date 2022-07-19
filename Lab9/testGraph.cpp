#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include "Graph.h"

int getRand(int n)
{
	return rand() % n;
}

Graph* makeSparseUDWG(int n)
{
	Graph* graph = new Graph(n, false, false);

	for (int i = 0; i < (2 * n) - 1; i++)
	{
		int v1 = getRand(n);
		int v2 = getRand(n);
		int w = getRand(100) + 1;

		while (graph->edgeExists(v1, v2))
		{
			v1 = getRand(n);
			v2 = getRand(n);
		}

		graph->insertEdge(v1, v2, w);
	}

	return graph;
}

Graph* makeDenseDWG(int n)
{
	Graph* graph = new Graph(n, true, true);
	int min = ((n - 2) * n) / 2;
	int max = n * (n + 1);
	for (int i = min; i < max; i++)
	{
		int v1 = getRand(n);
		int v2 = getRand(n);
		int w = getRand(100) + 1;

		while (graph->edgeExists(v1, v2))
		{
			v1 = getRand(n);
			v2 = getRand(n);
		}

		graph->insertEdge(v1, v2, w);
	}

	return graph;
}

void printGraph(Graph* graph, std::string fileName)
{
	graph->printEdges(fileName);
}

int main()
{
	srand(time(0));

	Graph* graph = makeSparseUDWG(25);
	printGraph(graph, "sparse25.txt");

	delete graph;
	return 0;
}