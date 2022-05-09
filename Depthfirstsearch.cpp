// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graphs {
  int numofVertices;
  list<int> *adjacencyLists;
  bool *visited;

   public:
  Graphs(int Vertex);
  void addEdge(int source, int destination);
  void DFSearch(int vertex);
};

// Initialize graph
Graphs::Graphs(int vertices) {
  numofVertices = vertices;
  adjacencyLists = new list<int>[vertices];
  visited = new bool[vertices];
}

// Add edges
void Graphs::addEdge(int src, int dest) {
  adjacencyLists[src].push_front(dest);
}

// DFS algorithm
void Graphs::DFSearch(int vertex) {
  visited[vertex] = true;
  list<int> adjacencyList = adjacencyLists[vertex];

  cout << vertex << " ";

  list<int>::iterator a;
  for (a = adjacencyList.begin(); a != adjacencyList.end(); ++a)
    if (!visited[*a])
      DFSearch(*a);
}

int main() {
  Graphs g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);

  g.DFSearch(2);

  return 0;
}
