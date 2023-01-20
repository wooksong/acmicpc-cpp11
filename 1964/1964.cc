#include <iostream>

constexpr int64_t MOD = 45678;

int main() {
    int64_t N, ans;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::cin >> N;

    ans = 5;
    for (int i = 1; i < N; ++i) {
        ans += (5 * (i + 1) - (i * 2 + 1));
    }

    std::cout << ans % MOD << "\n";

    return 0;
}
