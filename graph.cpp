// GRAPH IMPLEMENTATIONS
// ADJACENCY LIST // ADJACENCY MATRIX 

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// a recursive function to do dfs
void dfs_recursive(vector<vector<int>>& graph, vector<bool>& visited, int source) {
    cout << source << endl;
    visited[source] = true;
    
    for(int i = 0; i < graph.size(); i++) {
        if(graph[source][i] != 0 && !visited[i]) {
            dfs_recursive(graph, visited, i);
        }
    }
}

// an iterative function to do dfs using stack
void dfs_iterative(vector<vector<int>>& graph, int source) {
    stack<int> st;
    vector<bool> discovered(graph.size(), false);
    
    st.push(source);
    
    while(st.size() != 0) {
        source = st.top();
        st.pop();
        
        if(discovered[source]) {
            continue;
        }
        else {
            discovered[source] = true;
            cout << source << endl;
        }
        
        for(int i = 0; i < graph.size(); i++) {
            if(graph[source][i] == 1 && discovered[i] == false) {
                st.push(i);
            }
        }
    }
}


// bfs using queue
void bfs(vector<vector<int>>& graph, int source) {
    queue<int> q;
    vector<bool> visited(graph.size(), false);
    
    visited[source] = true;
    q.push(source);
    
    while(q.size() != 0) {
        int removed = q.front();
        q.pop();
        cout << removed << endl;
        
        for(int i = 0; i < graph.size(); i++) {
            if(graph[removed][i] == 1 && visited[i] == false) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}



// adjacency list representation
class Graph1 {
    int V;
    list<int> *l;

    public: 
        Graph1(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void add_edge(int u, int v) {
            l[u].push_back(v);
            l[v].push_back(u);
        }
};


// adjacency matrix representation
class Graph2 {
    int **graph;
public:
    Graph2(int rows, int cols) {
        graph = new int*[rows];
        for(int i = 0; i < rows; i++) {
            graph[i] = new int[cols];
        }
    }

    void connect(int source, int destination, int weight) {
        graph[source][destination] = weight;
        graph[destination][source] = weight;
    }
    
    int** get_graph() {
        return graph;
    }
};


int main() {

    // 0------1------2
    // |      |
    // 3------4------5


    Graph1 g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    return 0;
}