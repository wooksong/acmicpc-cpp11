#include <iostream>
#include <vector>

constexpr size_t LIMIT_NUM = 1e6 + 1;

std::vector<int> dp(LIMIT_NUM, 0);

int main() {
    int N;
    std::cin >> N;
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
    }

    std::cout << dp[N] << "\n";
    return 0;
}
