#include <iostream>

constexpr uint32_t MAX_N = 11;

uint32_t dp[MAX_N][MAX_N];
uint32_t binomial(uint32_t n, uint32_t k);
static inline uint32_t min(uint32_t l, uint32_t r) {
    if (l > r)
        return r;
    return l;
}
int main() {
    uint32_t N, K;

    std::cin >> N >> K;
    std::cout << binomial(N, K) << "\n";
    return 0;
}

uint32_t binomial(uint32_t n, uint32_t k) {
    uint32_t i, j;

    for (i = 1; i <= n; ++i) {
        for (j = 0; j <= min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}
