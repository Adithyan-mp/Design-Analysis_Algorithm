#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Class for Disjoint Set Union (DSU)
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n, -1);
        rank.resize(n, 1);
    }

    // Find operation with path compression
    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }

        int x = find(parent[i]);

        parent[i] = x;
        rank[x] += 1;

        return x;
    }

    // Union operation with rank optimization
    int unite(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);

        if (parentx != parenty) {
            if (rank[parentx] >= rank[parenty]) {
                parent[parenty] = parentx;
                rank[parentx] += rank[parenty];
            } else {
                parent[parentx] = parenty;
                rank[parenty] += rank[parentx];
            }
            return 0;
        } else {
            return -1; // Already in the same set
        }
    }
};

// Class for representing an undirected graph
class Graph {
private:
    vector<vector<int>> edge_list;
    vector<int> vertex_list;
    int vertex;
    int edges;

public:
    Graph(int vertex, int edges) : vertex(vertex), edges(edges) {
        edge_list.resize(edges, vector<int>(3, -1));
    }

    // Input edges and their weights from the user
    void putEdgeList() {
        cout << "Enter the edges and weight respectively: \n";
        for (int i = 0; i < edges; i++) {
            cout << "Enter the weight: ";
            cin >> edge_list[i][0];
            cout << "Edge1 and Edge2 respectively: ";
            cin >> edge_list[i][1] >> edge_list[i][2];
        }
    }

    // Input vertices from the user
    void getVertexList() {
        cout << "ENTER THE VERTICES: \n";
        vertex_list.resize(vertex);
        for (int i = 0; i < vertex; i++) {
            cout << "Vertex (" << i + 1 << "): ";
            cin >> vertex_list[i];
        }
    }

    // Getter methods
    int getNVertex() const {
        return vertex;
    }

    int getNEdge() const {
        return edges;
    }

    vector<int> getEdge(int i) const {
        return edge_list[i];
    }

    vector<vector<int>> getEdgeList()  {
        return edge_list;
    }
};

// Class for implementing Kruskal's algorithm
class Kruskal {
private:
    DSU *dsu;
    Graph *graph;
    int vertex;
    int edge;

public:
    Kruskal(int vertex, int edge) : vertex(vertex), edge(edge) {
        dsu = new DSU(vertex);
        graph = new Graph(vertex, edge);
    }

    // Destructor to free allocated memory
    ~Kruskal() {
        delete dsu;
        delete graph;
    }

    // Kruskal's algorithm to find the Minimum Spanning Tree (MST)
    int minSpanningTree() {
        int minimum = 0;
        string usedEdge;
        vector<vector<int>> edge_list = graph->getEdgeList();
        
        // Sort edges based on weight
        sort(edge_list.begin(), edge_list.end());

        // Iterate through sorted edges
        for (int i = 0; i < edge; i++) {
            int parent1 = dsu->find(edge_list[i][1]);
            int parent2 = dsu->find(edge_list[i][2]);
            
            // Check if adding the edge forms a cycle
            if (parent1 != parent2) {
                // Add the edge to the MST
                dsu->unite(edge_list[i][1], edge_list[i][2]);
                minimum += edge_list[i][0];
                usedEdge.append(to_string(edge_list[i][1]) + "->" + to_string(edge_list[i][2]) + " ");
            }
        }
        
        // Print the edges used in the MST
        cout << "Used Edges: " << usedEdge << endl;
        return minimum;
    }

    // Getter method for the graph
    Graph* getGraph() const {
        return graph;
    }
};

// Main function
int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    // Create an instance of Kruskal's algorithm
    Kruskal kruskal(vertices, edges);

    // Input the edges from the user
    kruskal.getGraph()->putEdgeList();

    // Find and print the minimum spanning tree weight
    int result = kruskal.minSpanningTree();
    cout << "Minimum Spanning Tree Weight: " << result << endl;

    return 0;
}
