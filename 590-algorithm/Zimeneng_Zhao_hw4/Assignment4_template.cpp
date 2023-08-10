#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
using namespace std;

class Graph { // graph class
    // add necessary attributes to represent graph
public:
    // storaging all of vertices we have tranversed
    map<int, bool> visited;
    // storaging all the vector of the vertices
    map<int, list<int> > adj;


    //for directed graph, adding vectors as they represented ,for undirected graph,adding all of vectors and swap head and tail, then adding the vectors again.  .
    void addEdge(int u, int v);
    void BFS(int startNode);
    void DFS(int startNode);
};

 void Graph::addEdge(int u, int v) {
      //add a new element at the end of the vector
      adj[u].push_back(v);
  }

 void Graph::BFS(int startNode){
     // implement BFS
     //suppose all of vertices are not visited
     //storaging nodes which are visiting
     queue<int> q;

     visited[startNode] = true;
     q.push(startNode);

    while(!q.empty()){
        startNode = q.front();
        cout<< startNode <<" ";
        q.pop();

        for(auto i : adj[startNode]){
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
  }
void Graph::DFS(int startNode){
      // implement DFS
      //suppose all of vertices are not visited
    cout << startNode << " ";
    visited[startNode] = true;
    for (auto i : adj[startNode]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
};


int main(){
  // main function

    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 9);
    g.addEdge(9, 10);
    g.addEdge(9, 7);
    g.addEdge(7, 10);
    g.addEdge(10, 3);

    cout << "Breadth First Traversal (starting from vertex 1): ";
    g.BFS(1); // perform BFS starting from vertex 1
    cout << endl;

    g.visited.clear();
    cout << "Depth First Traversal (starting from vertex 1): ";
    g.DFS(1); // perform DFS starting from vertex 1
    cout << endl;

    return 0;

}
