#include <iostream>
#include <vector>

constexpr size_t LIMIT_NUM = 11;
std::vector<uint64_t> dp(LIMIT_NUM, 0);
int main() {
    int T;
    uint64_t N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // freopen("input.txt", "r", stdin);
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> N;
        for (uint64_t i = 4; i <= N; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        std::cout << dp[N] << "\n";
    }

    return 0;
}
