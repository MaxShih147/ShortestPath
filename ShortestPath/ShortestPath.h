#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

#include "Graph.h"

class ShortestPathSolver {
protected:
	Graph * graph;
	int from;
	int to;
public:
	//ShortestPathSolver(Graph* g) : graph(g) {}
	ShortestPathSolver() {}
	void SetGraph(Graph *g) {
		graph = g;
	}
	virtual void Execute(int start, int end) = 0;
	virtual void Show() = 0;
};


//Purpose: Implementation of Dijkstra's algorithm which finds the shortest
//path from a start node to every other node in a weighted graph. 
//Time complexity: O(n^2)

class Dijkstra : public ShortestPathSolver {
private:
	std::vector<int> parent;
public:
	void Execute(int start, int end);
	void Show();
};

void Dijkstra::Execute(int start, int end) {

	from = start;
	to = end;

	const int MAX_WEIGHT = 100000;

	std::vector<int> distance(graph->edges.size(), MAX_WEIGHT);
	std::vector<bool> visited(graph->edges.size(), false);
	parent.resize(graph->edges.size(), -1);

	int current = start;
	distance[current] = 0;

	while (!visited[current]) {

		visited[current] = true;

		int next = current;
		int _min = MAX_WEIGHT;
		for (auto e : graph->edges[current]) {
			if (distance[current] + e.w < distance[e.to]) {
				distance[e.to] = distance[current] + e.w;
				parent[e.to] = current;
			}
			if (!visited[e.to] && (distance[e.to] < _min)) {
				next = e.to;
				_min = distance[e.to];
			}
		}
		current = next;
	}
}

void Dijkstra::Show() {

	std::vector<int> path;
	int v = to;
	while (v != -1) {
		path.push_back(v);
		v = parent[v];
	}
	std::cout << "From = " << from << "\n";
	std::cout << "To = " << to << "\n";
	std::cout << "Shortest path = ";
	for_each(
		path.rbegin(), path.rend(),
		[](int i) { std::cout << i << " "; }
	);
}

