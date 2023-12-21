#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
    int v;

public:
    DSU(int vertex) {
        v = vertex;
        parent.resize(v, -1);
        rank.resize(v, 1);
    }

    int find(int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        int x = find(parent[vertex]);
        parent[vertex] = x;
        rank[vertex] += rank[x];
        return x;
    }

    void unite(int x, int y) {
        int x1 = find(x);
        int y1 = find(y);

        if (x1 != y1) {
            if (rank[x1] >= rank[y1]) {
                parent[y1] = x1;
                rank[x1] += rank[y1];
            } else {
                parent[x1] = y1;
                rank[y1] += rank[x1];
            }
        }
    }
};

int kruskal(vector<vector<int>>& edge_list) {
    sort(edge_list.begin(), edge_list.end());
    int row = edge_list.size();
    DSU set(row);
    int cost = 0;

    for (int i = 0; i < row; i++) {
        int weight = edge_list[i][0];
        int u = edge_list[i][1];
        int v = edge_list[i][2];

        if (set.find(u) != set.find(v)) {
            set.unite(u, v);
            cost += weight;
        }
    }

    return cost;
}
