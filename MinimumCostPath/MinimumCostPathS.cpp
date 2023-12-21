#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void trace_back(vector<vector<int>>& dp, vector<vector<int>>& C, int row, int column) {
    cout<<C[row-1][column-1];
    for (int i = row - 1; i > 1;) {
        for (int j = column - 1; j >1;) {
            int temp = min(dp[i - 1][j], dp[i][j - 1]);

            if (temp > dp[i - 1][j - 1]) {
                cout << "->" << C[i - 1][j - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    cout << "->" << C[i - 1][j];
                    i--;
                } else {
                    cout << "->" << C[i][j - 1];
                    j--;
                }
            }
        }
    }
    cout<<"->"<<C[0][0]<<endl;
}

int miniCostPath(vector<vector<int>>& C, int row, int column) {
    vector<vector<int>> dp(row, vector<int>(column, 0));
    dp[0][0] = C[0][0];

    for (int i = 1; i < row; i++) {
        dp[i][0] = C[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < column; i++) {
        dp[0][i] = C[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < column; j++) {
            int temp = min(dp[i - 1][j], dp[i][j - 1]);

            if (temp > dp[i - 1][j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + C[i][j];
            } else {
                dp[i][j] = temp + C[i][j];
            }
        }
    }

    cout << "path is : ";
    trace_back(dp, C, row, column);
    return dp[row - 1][column - 1];
}

int main() {
    // Example usage
    const int row = 2;
    const int column = 2;
    vector<vector<int>> C(row, vector<int>(column, 0));
    int val = 1;
    C={
        {1,2},
        {3,4}
    };

    cout << "Minimum Cost: " << miniCostPath(C, row, column) << endl;

    return 0;
}
