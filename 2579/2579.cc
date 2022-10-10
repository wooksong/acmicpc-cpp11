#include <iostream>

constexpr int MAX_NUM_STEPS = 10001;
int dp[MAX_NUM_STEPS];

int main() {
    int scores[MAX_NUM_STEPS];
    int num_steps;

    freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> num_steps;

    for (int i = 1; i <= num_steps; ++i) {
        std::cin >> scores[i];
    }
    dp[1] = scores[1];
    dp[2] = scores[1] + scores[2];
    dp[3] = std::max(scores[1] + scores[3], scores[2] + scores[3]);

    for (int i = 4; i <= num_steps; ++i) {
        dp[i] = scores[i];
        dp[i] += std::max(scores[i - 1] + dp[i - 3], dp[i - 2]);
    }
    std::cout << dp[num_steps] << "\n";

    return 0;
}
