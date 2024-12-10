#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // Number of vertices
    int V;
    
    // Adjacency matrix to represent the graph
    vector<vector<int>> adjMatrix;
    
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        
        // Initialize the adjacency matrix with 0s
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    
    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Add an edge from u to v
        adjMatrix[v][u] = 1;  // Add an edge from v to u (for undirected graph)
    }
    
    // Function to display the graph (adjacency matrix)
    void displayGraph() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
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
    
    // Display the adjacency matrix
    g.displayGraph();
    
    return 0;
}
