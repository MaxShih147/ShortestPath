#include "ShortestPath.h"

class Example {
public:
	virtual void Execute() = 0;
};
class Example_1 : public Example {
public:
	void Execute() {
		Graph *graph = new Graph(5);
		graph->InsertEdge(0, 1, 4, false);
		graph->InsertEdge(0, 2, 1, false);
		graph->InsertEdge(2, 1, 1, false);
		graph->InsertEdge(2, 3, 5, false);
		graph->InsertEdge(1, 3, 3, false);
		graph->InsertEdge(1, 4, 1, false);
		graph->InsertEdge(3, 4, 2, false);

		ShortestPathSolver *solver = new Dijkstra;
		solver->SetGraph(graph);
		solver->Execute(0, 4);
		solver->Show();

		delete graph, solver;
	}
};
class Example_2 : public Example {
public:
	void Execute() {
		Graph *graph = new Graph(7);
		graph->InsertEdge(0, 1, 32, false);
		graph->InsertEdge(0, 5, 3, false);
		graph->InsertEdge(1, 2, 21, false);
		graph->InsertEdge(1, 4, 12, false);
		graph->InsertEdge(1, 5, 7, false);
		graph->InsertEdge(2, 4, 6, false);
		graph->InsertEdge(2, 5, 2, false);
		graph->InsertEdge(2, 6, 11, false);
		graph->InsertEdge(3, 4, 13, false);
		graph->InsertEdge(3, 6, 9, false);

		ShortestPathSolver *solver = new Dijkstra;
		solver->SetGraph(graph);
		solver->Execute(0, 6);
		solver->Show();

		delete graph, solver;
	}
};


int main() {
	Example *example = new Example_2;
	example->Execute();
	delete example;
    return 0;
}