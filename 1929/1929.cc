#include <iostream>
#include <vector>

constexpr size_t UPPER_LIMIT = 1000001;

int main() {
    uint32_t M, N;
    std::vector<bool> sieve;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    std::cin >> M >> N;

    sieve = std::vector<bool>(N + 1, true);
    sieve[0] = false;
    sieve[1] = false;

    for (uint32_t i = 2; i <= N; ++i) {
        for (uint32_t j = 2; j * i <= N; ++j) {
            sieve[i * j] = false;
        }
    }

    for (uint32_t i = M; i <= N; ++i) {
        if (!sieve[i])
            continue;
        std::cout << i << "\n";
    }
    return 0;
}
