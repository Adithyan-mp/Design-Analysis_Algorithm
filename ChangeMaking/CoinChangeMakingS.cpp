#include<iostream>
#include<climits>
using namespace std;

// Change: The return type of the 'min' function should be int.
int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}

void trace_back(int *coin, int n, int d, int *D, int mincoin) {
    for (int i = n; i > 0;) {
        int temp = INT_MAX;
        int coin_taken = 0;
        for (int j = d - 1; j >= 0; j--) {
            if (i >= D[j] && temp > coin[i - D[j]]) {
                temp = coin[i - D[j]];
                coin_taken = D[j];
            }
        }
        if (temp != INT_MAX) {
            cout << coin_taken << " ";
            i = i - coin_taken;
        } else {
            break;
        }
    }
}


int ChangeMake(int *D, int n, int d) {
    int coin[n + 1];
    fill(coin, coin + n + 1, INT_MAX); // Initialize the array with INT_MAX
    coin[0] = 0;

    for (int i = 1; i <= n; i++) {
        int temp = INT_MAX;
        for (int j = 0; j < d; j++) {
            if (i >= D[j]) {
                temp = min(temp, coin[i - D[j]]);
            }
        }
        if(temp!=INT_MAX)
            coin[i] =temp + 1;
    }

    cout << "Coins taken: ";
    trace_back(coin, n, d, D, coin[n]);
    return coin[n];
}


// Change: Added a main function for testing.
int main() {
    int D[] = {3,5}; // Denominations
    int n = 13;          // Amount to make change for
    int d = sizeof(D) / sizeof(D[0]); // Number of denominations

    int result = ChangeMake(D, n, d);

    cout << " \n Minimum number of coins required: " << result << endl;

    return 0;
}
