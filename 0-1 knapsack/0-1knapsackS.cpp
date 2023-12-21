#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void trace_back(vector<int>& weight, vector<int>& cost, vector<vector<int>>& dp, int nweight, int capacity) {
    int i = nweight, j = capacity;
    while (i > 0 && j > 0) {
        if (j - weight[i] >= 0 && dp[i][j] == cost[i] + dp[i - 1][j - weight[i]]) {
            cout << "->" << "(weight, cost): " << weight[i] << "," << cost[i];
            j = j - weight[i];
        }
        i--;
    }
}

int knapSack(vector<int>& weight, vector<int>& cost, int nweight, int capacity) {
    vector<vector<int>> dp(nweight + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= nweight; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], cost[i] + dp[i - 1][j - weight[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    trace_back(weight, cost, dp, nweight, capacity);
    return dp[nweight][capacity];
}

int main() {
    vector<int> weight = {0, 1, 2, 3};
    vector<int> cost = {0, 60, 100, 120};
    int nweight = 3;
    int capacity = 5;

    int result = knapSack(weight, cost, nweight, capacity);
    cout << "\nMaximum Value: " << result << endl;

    return 0;
}
