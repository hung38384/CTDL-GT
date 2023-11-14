#include <iostream>
#include <vector>
#include <algorithm>

struct Artifact {
    int weight;
    int profit;
};

bool compare(Artifact a, Artifact b) {
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB;
}

int knapsackGreedy(int W, std::vector<Artifact>& artifacts) {
    std::sort(artifacts.begin(), artifacts.end(), compare);

    int totalProfit = 0;
    for (const auto& artifact : artifacts) {
        if (W >= artifact.weight) {
            W -= artifact.weight;
            totalProfit += artifact.profit;
        } else {
            double fraction = (double)W / artifact.weight;
            totalProfit += fraction * artifact.profit;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int W = 50;
    std::vector<Artifact> artifacts = {{10, 60}, {20, 100}, {30, 120}};

    int result = knapsackGreedy(W, artifacts);

    std::cout << "Maximum total profit (greedy): " << result << std::endl;

    return 0;
}
