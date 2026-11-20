#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int n, int c, vector<int>& weight, vector<int>& profits) {

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {

        for (int w = 1; w <= c; w++) {

            // If item cannot fit
            if (weight[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else {
                // Maximum of:
                // 1. Not taking the item
                // 2. Taking the item
                dp[i][w] = max(
                    dp[i - 1][w],
                    profits[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
        }
    }

    return dp[n][c];
}

int main() {

    int n, c;

    cin >> n;

    vector<int> weight(n);
    vector<int> profits(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    cin >> c;

    int result = knapsack(n, c, weight, profits);

    cout << "Maximum value = " << result << endl;

    return 0;
}