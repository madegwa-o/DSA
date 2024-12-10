#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS using recursion
    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g(5);  // Graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS starting from node 0:" << endl;
    g.DFS(0);  // Perform DFS starting from vertex 0

    return 0;
}
