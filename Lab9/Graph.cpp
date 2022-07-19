#include "Graph.h"

Edge::Edge(int source, int target, int weight)
{
	source_ = source;
	target_ = target;
	weight_ = weight;
}

Graph::Graph()
{
	E_ = 0;
	V_ = 0;
	directed_ = false;
	dense_ = false;
}

Graph::Graph(int vertices, bool directed, bool dense)
{
	E_ = 0;
	V_ = vertices;
	directed_ = directed;
	dense_ = dense;
	if (dense_)
	{
		createDense();
	}
	else
	{
		createSparse();
	}
}

bool Graph::isEmpty()
{
	return V_ == 0;
}

int Graph::totalEdges()
{
	return E_;
}

int Graph::totalVertices()
{
	return V_;
}

void Graph::createSparse()
{
	adjacencyList_.resize(V_);
}

void Graph::createDense()
{
	adjacencyMatrix_.resize(V_);

	for (int i = 0; i < V_; i++)
	{
		for (int j = 0; j < V_; j++)
		{
			adjacencyMatrix_[i].push_back(-1);
		}
	}
}

void Graph::insertEdge(int v1, int v2, int w)
{
	if (dense_)
	{
		adjacencyMatrix_[v1][v2] = w;
		if (!directed_ && v1 != v2)
		{
			adjacencyMatrix_[v2][v1] = w;
		}
	}
	else
	{
		adjacencyList_[v1].push_back(new Edge(v1, v2, w));
		if (!directed_ && v1 != v2)
		{
			adjacencyList_[v2].push_back(new Edge(v2, v1, w));
		}
	}

	E_++;
}

void Graph::adjacent(int v)
{
	if (!dense_)
	{
		size_t size = adjacencyList_[v].size();

		if (directed_)
		{
			for (size_t i = 0; i < size; i++)
			{
				std::cout << "< " << adjacencyList_[v][i]->source_;
				std::cout << ", " << adjacencyList_[v][i]->target_;
				std::cout << ", " << adjacencyList_[v][i]->weight_ << " >" << std::endl;
			}
		}
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				std::cout << "( " << adjacencyList_[v][i]->source_;
				std::cout << ", " << adjacencyList_[v][i]->target_;
				std::cout << ", " << adjacencyList_[v][i]->weight_ << " )" << std::endl;
			}
		}
	}
	else
	{
		size_t size = adjacencyMatrix_[v].size();

		if (directed_)
		{
			for (size_t i = 0; i < size; i++)
			{
				if (adjacencyMatrix_[v][i] != -1)
				{
					std::cout << "< " << v;
					std::cout << ", " << i;
					std::cout << ", " << adjacencyMatrix_[v][i] << " >" << std::endl;
				}
			}
		}
		else
		{
			for (size_t i = 0; i < size; i++)
			{
				if (adjacencyMatrix_[v][i] != -1)
				{
					std::cout << "( " << v;
					std::cout << ", " << i;
					std::cout << ", " << adjacencyMatrix_[v][i] << " )" << std::endl;
				}
			}
		}
	}
}

bool Graph::edgeExists(int v1, int v2)
{
	if (dense_)
	{
		return adjacencyMatrix_[v1][v2] != -1;
	}
	else
	{
		size_t size = adjacencyList_[v1].size();

		for (size_t i = 0; i < size; i++)
		{
			if (adjacencyList_[v1][i]->target_ == v2)
			{
				return true;
			}
		}

		return false;
	}
}

void Graph::printEdges(std::string fileName)
{
	int* visited = new int[V_] {0};

	std::ofstream outFile;
	outFile.open(fileName);
	outFile << V_ << std::endl;

	if (dense_)
	{
		for (int i = 0; i < adjacencyMatrix_.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix_[i].size(); j++)
			{
				if (visited[j] != 0 && adjacencyMatrix_[i][j] != -1)
				{
					outFile << i << " " << j << " " << adjacencyMatrix_[i][j] << std::endl;
				}
			}
			visited[i]++;
		}
	}
	else
	{
		for (int i = 0; i < adjacencyList_.size(); i++)
		{
			for (int j = 0; j < adjacencyList_[i].size(); j++)
			{
				int target = adjacencyList_[i][j]->target_;
				int weight = adjacencyList_[i][j]->weight_;
				if (visited[target] != 0)
				{
					outFile << i << " " << target << " " << weight << std::endl;
				}
			}
			visited[i]++;
		}
	}

	outFile.close();
}

Graph::~Graph()
{
	for (size_t i = 0; i < adjacencyList_.size(); i++)
	{
		for (size_t j = 0; j < adjacencyList_[i].size(); j++)
		{
			delete adjacencyList_[i][j];
			adjacencyList_[i][j] = nullptr;
		}
	}
}