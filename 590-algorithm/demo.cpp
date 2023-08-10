#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Graph class to represent a graph using adjacency list
class Graph {
    int V; // number of vertices
    vector<vector<int>> adj; // adjacency list

public:
    Graph(int V) { // constructor
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) { // function to add an edge to the graph
        adj[v].push_back(w);
    }

    void BFS(int start) { // function to perform BFS
        vector<bool> visited(V, false); // initialize all vertices as not visited

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (auto i = adj[current].begin(); i != adj[current].end(); ++i) {
                if (!visited[*i]) {
                    q.push(*i);
                    visited[*i] = true;
                }
            }
        }
    }

    void DFS(int start) { // function to perform DFS
        vector<bool> visited(V, false); // initialize all vertices as not visited

        stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                for (auto i = adj[current].begin(); i != adj[current].end(); ++i) {
                    if (!visited[*i]) {
                        s.push(*i);
                    }
                }
            }
        }
    }
};

int main() {
    Graph g(5); // create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2); // perform BFS starting from vertex 2
    cout << endl;

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2); // perform DFS starting from vertex 2
    cout << endl;

    return 0;
}
