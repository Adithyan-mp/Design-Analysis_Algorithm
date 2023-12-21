#include<iostream>
#include<vector>
#include<climits>

class CoinChangeMaking {
private:
    std::vector<int> cointake;   // Vector to store selected denominations
    std::vector<int> denomi;     // Vector to store denominations
    std::vector<int> mincoin;    // Vector to store minimum coins needed for each amount
    int change;                   // Target amount for which change is to be made
    int ndenomi;                  // Number of denominations

public:
    CoinChangeMaking() {}

    CoinChangeMaking(int change, int ndenomi) {
        this->change = change;
        mincoin.resize(change + 1, INT_MAX);
        this->ndenomi = ndenomi;
    }

    // Method to input data for denominations and target amount
    void putData(int change) {
        this->change = change;
        mincoin.resize(change + 1, INT_MAX);
        std::cout << "HOW MANY DENOMINATION ARE THERE : ";
        std::cin >> ndenomi;

        // Input validation for non-negative number of denominations
        if (ndenomi < 0) {
            std::cerr << "Invalid number of denominations.\n";
            exit(EXIT_FAILURE);
        }

        denomi.resize(ndenomi, 0);
        std::cout << "\n ENTER THE DENOMINATION IN INCREASING ORDER : \n";
        for (int i = 0; i < ndenomi; i++) {
            std::cout << "DENOMINATION " << i + 1 << " : ";
            std::cin >> denomi[i];
        }
    }

    // Overloaded method to input data without changing the target amount
    void putData() {
        denomi.resize(ndenomi, 0);
        std::cout << "\n ENTER THE DENOMINATION IN INCREASING ORDER : \n";
        for (int i = 0; i < ndenomi; i++) {
            std::cout << "DENOMINATION " << i + 1 << " : ";
            std::cin >> denomi[i];
        }
    }

    // Function to find the minimum number of coins needed to make change
    int minCoin();

    // Function to trace back and print the selected denominations
    void trace_back();

    // Helper function to find the minimum of two integers
    int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }
};

// Implementation of minCoin function
int CoinChangeMaking::minCoin() {
    mincoin[0] = 0;
    for (int i = 1; i <= change; i++) {
        int temp = INT_MAX;
        for (int j = 0; j < ndenomi; j++) {
            if (i >= denomi[j]) {
                temp = min(temp, mincoin[i - denomi[j]]) ;
            }
        }
        mincoin[i] = temp+1;
    }

    trace_back();
    return mincoin[change];
}

// Implementation of trace_back function
void CoinChangeMaking::trace_back() {
    for (int i = change; i > 0;) {
        int mincoinindex = 0;
        int temp = INT_MAX;
        for (int j = ndenomi - 1; j >= 0; j--) {
            if (i >= denomi[j] && temp > mincoin[i - denomi[j]]) {
                temp = mincoin[i - denomi[j]];
                mincoinindex = i - denomi[j];
            }
        }
        if (temp != INT_MAX) {
            cointake.push_back(i-mincoinindex);
            i = mincoinindex;
        } else {
            // No valid denomination found, break the loop
            break;
        }
    }
    
    // Print the selected denominations
    std::cout << "THE COINS TAKEN : ";
    for (int i = 0; i < cointake.size(); i++) {
        int j = cointake[i];  // Retrieve the index of the selected denomination
        std::cout << j << " ";
    }
}

// Main function
int main() {
    CoinChangeMaking coinChange;
    int change;
    std::cout << "Enter the amount of change: ";
    std::cin >> change;
    coinChange.putData(change);
    int minCoins=0;
    minCoins = coinChange.minCoin();
    std::cout << "\n Minimum number of coins required: " << minCoins << std::endl;

    return 0;
}
