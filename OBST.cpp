#include <iostream>
#include <climits>
using namespace std;

int optimalCost(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += freq[k];
            }

            for (int r = i; r <= j; r++) {
                int c = (r > i ? cost[i][r - 1] : 0) +
                        (r < j ? cost[r + 1][j] : 0) + sum;

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    int keys[n], freq[n];
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    int result = optimalCost(keys, freq, n);
    cout << "Optimal cost of OBST: " << result << endl;

    return 0;
}
