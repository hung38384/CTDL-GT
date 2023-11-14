#include <iostream>
#include <vector>

int knapsackDynamic(int W, std::vector<int>& weights, std::vector<int>& profits, int N) {
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int W = 50;
    std::vector<int> weights = {10, 20, 30};
    std::vector<int> profits = {60, 100, 120};
    int N = weights.size();

    int result = knapsackDynamic(W, weights, profits, N);

    std::cout << "Maximum total profit (dynamic programming): " << result << std::endl;

    return 0;
}
