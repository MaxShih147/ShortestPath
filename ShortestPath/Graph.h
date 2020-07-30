#pragma once
#include <vector>

class Node {
public:
	int to;
	int w;
	Node(int _to, int _w) : to(_to), w(_w) {}
};

class Graph {
public:
	std::vector<std::vector<Node>> edges;
public:
	Graph(int nodeNumber) {
		edges.resize(nodeNumber);
	}
	void InsertEdge(int from, int to, int weight, bool directed);
};

void Graph::InsertEdge(int from, int to, int weight, bool directed) {
	edges[from].push_back(Node(to, weight));
	if (!directed) {
		edges[to].push_back(Node(from, weight));
	}
}