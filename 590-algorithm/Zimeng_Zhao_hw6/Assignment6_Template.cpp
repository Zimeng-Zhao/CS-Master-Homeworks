#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Vertex{
public:
    int id;
    Vertex(int id){
        this->id = id;
    }
};

class Edge{
public:
    Vertex* start;
    Vertex* end;
    int weight;
    Edge(Vertex* start, Vertex* end, int weight){
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

class Graph{
public:
    int V;
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    Graph(int V){
        this->V = V;
        for(int i = 1; i <= V; i++){
            Vertex* vertex = new Vertex(i);
            vertices.push_back(vertex);//adds a new element at the end of the vector.
        }
    }

    void addEdge(int u, int v, int w){
        Edge* edge = new Edge(vertices[u - 1], vertices[v - 1], w);
        edges.push_back(edge);
    }

    void floydWarshall(){
        int dist[V][V];

        for(int i = 0; i < V; i++){//initialize a distance matrix
            for(int j = 0; j< V; j++){
                if(i == j){
                    dist[i][j] = 0;
                }
                else{
                    dist[i][j] = INT_MAX;
                }
            }
        }

        for(int i = 0; i < edges.size(); i++){//initialize the distance matrix
            Edge* edge = edges[i];
            int u = edge->start->id;
            int v = edge->end->id;
            int w = edge->weight;
            dist[u - 1][v - 1] = w;
        }

        for(int k = 0; k < V; k++){//implement floyd warshall algorithm
            for(int i = 0; i < V; i++){
                for(int j = 0; j < V; j++){
                    // dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    if (dist[i][j] > (dist[i][k] + dist[k][j])
                        && (dist[k][j] != INT_MAX
                            && dist[i][k] != INT_MAX))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][j] == INT_MAX){
                    cout << "INF";
                }
                else{
                    cout << dist[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main(){
    int V = 4;
    int E = 6;//number of edges in input graph
    Graph graph(V);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 4, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 1, 4);
    graph.addEdge(4, 2, 2);
    graph.addEdge(4, 3, 9);
    graph.floydWarshall();
    return 0;
}
