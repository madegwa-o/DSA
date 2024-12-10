#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
    // Number of vertices
    int V;
    
    // An array of lists to represent an adjacency list
    vector<list<int>> adjList;
    
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }
    
    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);  // Add v to u’s list
        adjList[v].push_back(u);  // Add u to v’s list (for undirected graph)
    }
    
    // Function to print the graph (display adjacency list)
    void displayGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ": ";
            for (auto& neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);
    
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 4);
    
    // Display the graph
    g.displayGraph();
    
    return 0;
}
