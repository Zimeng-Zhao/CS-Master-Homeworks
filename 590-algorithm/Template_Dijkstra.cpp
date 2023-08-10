#include <iostream>
using namespace std;

class Vertex {
public:
    char label;
    int dist;
    // add additional attribute and/or member function
};

class Edge {
public:
    Vertex* start;
    Vertex* end;
    int weight;

    // add additional attribute and/or member function
};

void dijkstra(Vertex* start) {
  //implement dijkstra's algo to find the shortest path
}

int main() {
    //complete the main function
    return 0;
}
