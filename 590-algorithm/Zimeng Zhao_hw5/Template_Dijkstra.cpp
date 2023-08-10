
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Edge;
class Vertex {
public:
    char label;
    int dist;
    // add additional attribute and/or member function
    bool visited;
    //a vector that holds all the edges that originate from the current vertex.
    vector<Edge*> edges;
    // pointer to previous vertex in the shortest path
    Vertex* prev;
    //a constructor for the Vertex class,this constructor initializes the member variables
    Vertex(char i) : label(i), dist(INT_MAX), visited(false){}
    // compare the distances of two vertices
    bool operator>(const Vertex& other) const{
        return  dist > other.dist;
    }
};

vector<Vertex*> vertices;

class Edge {
public:
    Vertex* start;
    Vertex* end;
    int weight;
    // add additional attribute and/or member function
    //a constructor for the Vertex class,this constructor initializes the member variables
    Edge(Vertex* s,Vertex* e, int w) :start(s), end(e), weight(w){}
};

void dijkstra(Vertex* start) {
  //implement dijkstra's algo to find the shortest path
    // set the distance of the starting vertex to 0
    start->dist = 0;
    // create a priority queue to store the vertices in order of their distance from the starting vertex
    priority_queue<Vertex*, vector<Vertex*>, greater<Vertex*>> pq;
    // insert the starting vertex into the priority queue
    pq.push(start);
    // while the priority queue is not empty
    while (!pq.empty()) {
        // remove the vertex with the smallest distance from the priority queue
        Vertex* v = pq.top();
        pq.pop();
        // if the vertex has already been visited, skip it
        if (v->visited) {
            continue;
        }
        // mark the vertex as visited
        v->visited = true;
        // for each edge from the current vertex
        for (Edge* e : v->edges) {
            // get the adjacent vertex
            Vertex* u = e->end;
            // if the adjacent vertex has already been visited, skip it
            if (u->visited) {
                continue;
            }
            // calculate the distance to the adjacent vertex via the current vertex
            int new_dist = v->dist + e->weight;
            // if the new distance is shorter than the current distance to the adjacent vertex
            if (new_dist < u->dist) {
                // update the distance of the adjacent vertex
                u->dist = new_dist;
                // set the previous vertex of the adjacent vertex to the current vertex
                u->prev = v;
                // insert the adjacent vertex into the priority queue
                pq.push(u);
            }
        }
    }
}


int main() {
    //complete the main function
    // create the vertices
    Vertex* A = new Vertex('A');
    Vertex* B = new Vertex('B');
    Vertex* C = new Vertex('C');
    Vertex* D = new Vertex('D');
    Vertex* E = new Vertex('E');
    Vertex* F = new Vertex('F');
    Vertex* G = new Vertex('G');

    // add the edges
    A->edges.push_back(new Edge(A, B, 1));
    B->edges.push_back(new Edge(B, A, 1));
    A->edges.push_back(new Edge(A, C, 3));
    C->edges.push_back(new Edge(C, A, 3));
    A->edges.push_back(new Edge(A, F, 10));
    F->edges.push_back(new Edge(F, A, 10));
    B->edges.push_back(new Edge(B, C, 1));
    C->edges.push_back(new Edge(C, B, 1));
    B->edges.push_back(new Edge(B, D, 7));
    D->edges.push_back(new Edge(D, B, 7));
    B->edges.push_back(new Edge(B, E, 5));
    E->edges.push_back(new Edge(E, B, 5));
    B->edges.push_back(new Edge(B, G, 2));
    G->edges.push_back(new Edge(G, B, 2));
    C->edges.push_back(new Edge(C, E, 3));
    E->edges.push_back(new Edge(E, C, 3));
    C->edges.push_back(new Edge(C, D, 9));
    D->edges.push_back(new Edge(D, C, 9));
    D->edges.push_back(new Edge(D, E, 2));
    E->edges.push_back(new Edge(E, D, 2));
    D->edges.push_back(new Edge(D, F, 1));
    F->edges.push_back(new Edge(F, D, 1));
    D->edges.push_back(new Edge(D, G, 12));
    G->edges.push_back(new Edge(G, D, 12));
    E->edges.push_back(new Edge(E, F, 2));
    F->edges.push_back(new Edge(F, E, 2));

    // add the vertices to the vector
    vertices.push_back(A);
    vertices.push_back(B);
    vertices.push_back(C);
    vertices.push_back(D);
    vertices.push_back(E);
    vertices.push_back(F);
    vertices.push_back(G);

    dijkstra(A);
    // print the shortest path to each vertex
    for (Vertex* v : vertices) {
        cout << "Shortest path to vertex " << v->label << ": ";
        if (v->dist == INT_MAX) {
            cout << "no path" << endl;
        } else {
            cout << v->dist << endl;
        }
    }
    return 0;
}





