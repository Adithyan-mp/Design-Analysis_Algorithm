#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Dijkstra {
private:
    int vertex;
    vector<vector<int>> graph;  // Adjacency matrix representing the graph
    vector<int> dist;           // Array to store the shortest distances
    vector<bool> sptset;        // Array to mark vertices included in the shortest path tree

public:
    Dijkstra(int vertex) {
        this->vertex = vertex;
        graph.resize(vertex, vector<int>(vertex, 0));
        dist.resize(vertex, INT_MAX);
        sptset.resize(vertex, false);
    }

    // Function to input the graph data
    void putData() {
        cout << "ENTER THE COST OF EDGE ELSE PUT 0 \n";
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                cout << "edge (" << i << "->" << j << ") : ";
                cin >> graph[i][j];
            }
        }
    }

    // Function to find the vertex with the minimum distance value, not yet included in the shortest path tree
    int minDistance() {
        int min = INT_MAX;
        int min_index = 0;

        for (int i = 0; i < vertex; i++) {
            if (!sptset[i] && dist[i] < min) {
                min = dist[i];
                min_index = i;
            }
        }

        return min_index;
    }

    // Function to run Dijkstra's algorithm
    void dijkstra(int source) {
        dist[source] = 0;

        for (int i = 0; i < vertex; i++) {
            int neighbour = minDistance();

            // Mark the selected vertex (neighbour) as included in the shortest path tree
            sptset[neighbour] = true;

            for (int j = 0; j < vertex; j++) {
                // Update the distance of vertex j if it's not in the shortest path tree,
                // there is an edge from neighbour to j, and the total distance is less than the current distance
                if (!sptset[j] && graph[neighbour][j] > 0 && dist[neighbour] + graph[neighbour][j] < dist[j]) {
                    dist[j] = dist[neighbour] + graph[neighbour][j];
                }
            }
        }
    }

    // Function to print the computed distances
    void printDistances() {
        cout << "Shortest distances from the source:\n";
        for (int i = 0; i < vertex; i++) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        }
    }
};

// Main function
int main() {
    int numVertices, sourceVertex;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Dijkstra dijkstraObj(numVertices);

    dijkstraObj.putData(); // Input the graph data

    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    dijkstraObj.dijkstra(sourceVertex); // Run Dijkstra's algorithm

    dijkstraObj.printDistances(); // Output the computed distances

    return 0;
}
