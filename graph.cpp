// GRAPH IMPLEMENTATIONS
// ADJACENCY LIST // ADJACENCY MATRIX 

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;

    public: 
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void add_edge(int u, int v) {
            l[u].push_back(v);
            l[v].push_back(u);
        }
};

int main() {

    // 0------1------2
    // |      |
    // 3------4------5


    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    return 0;
}