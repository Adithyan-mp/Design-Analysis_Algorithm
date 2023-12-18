#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CoinRow {
private:
    vector<int> coin;
    int capacity;
    vector<int> traceBack;

public:
    CoinRow() : traceBack(capacity + 1, 0) {
        cout << "enter the number of coin : ";
        cin >> capacity;
        coin.resize(capacity);
        for (int i = 0; i < capacity; i++) {
            cout << "enter the coin " << i + 1 << " : ";
            cin >> coin[i];
        }
    }

    int getCapacity() {
        return capacity;
    }

    void getCoin() {
        for (int i = 0; i < capacity; i++) {
            cout << "coin " << (i + 1) << " : " << coin[i] << "\n";
        }
    }

    int getMaxAmount();

    void backTrack() {
        cout << "coins are : \n";
        for (int i : traceBack) {
            cout << i << " , ";
        }
        cout << "\n";
    }
};

int CoinRow::getMaxAmount() {
    vector<int> maxAmount(capacity + 1, 0);
    maxAmount[0] = coin[0];
    maxAmount[1] = max(coin[1], maxAmount[0]);
    traceBack[0] = maxAmount[1];
    for (int i = 2; i <= capacity; i++) {
        maxAmount[i] = max(coin[i] + maxAmount[i - 2], maxAmount[i - 1]);
        if (maxAmount[i] == coin[i] + maxAmount[i - 2]) {
            traceBack.push_back(coin[i]);
        }
    }
    return maxAmount[capacity];
}

int main() {
    CoinRow obj;
    obj.getCoin();
    int max = obj.getMaxAmount();
    cout << "\n" << max << "\n";
    obj.backTrack();
    return 0;
}
