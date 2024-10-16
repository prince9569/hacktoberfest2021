#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int> weights, vector<int> values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build the dp table
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right corner of the table contains the maximum value
    return dp[n][W];
}

int main() {
    int n, W;

    // Input the number of items and the maximum weight capacity of the knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> values(n), weights(n);

    // Input the values and weights of the items
    cout << "Enter the values of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    // Call the knapsack function and display the result
    cout << "Maximum value in knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}
