#include <iostream>
#include <vector>

constexpr int MAX_N = 226;
constexpr int MAX_POW = 226 * 226;

int main() {
    std::vector<int> pows = std::vector<int>(MAX_N, 0);
    std::vector<int> dp = std::vector<int>(MAX_POW, 4);
    int i, j, N, min;

    std::cin >> N;

    for (int i = 1; i < MAX_N; ++i) {
        pows[i] = i * i;
    }

    dp[0] = 0;
    dp[1] = 1;

    i = 1;
    for (auto p = pows.begin(); p != pows.end(); ++p) {
        dp[*p] = 1;
    }

    for (i = 2; i <= N; ++i) {
        for (j = 1; j < MAX_N; ++j) {
            if (pows[j] > i)
                break;
        }

        min = dp[i];
        for (int k = 1; k < j; ++k) {
            min = std::min(min, dp[i - pows[k]] + 1);
        }
        dp[i] = min;
    }

    std::cout << dp[N] << "\n";
}
