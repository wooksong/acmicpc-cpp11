#include <iostream>
#include <vector>

constexpr size_t LIMIT_PRIME_N = 1001;

void build_sieve(std::vector<bool> &primes);
int main() {
    std::vector<bool> sieve = std::vector<bool>(LIMIT_PRIME_N, true);
    uint32_t cnt = 0;
    size_t N;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    build_sieve(sieve);
    for (uint32_t i = 0; i < N; ++i) {
        size_t n;

        std::cin >> n;
        if (sieve[n])
            cnt++;
    }

    std::cout << cnt << "\n";

    return 0;
}

void build_sieve(std::vector<bool> &primes) {
    primes[0] = false;
    primes[1] = false;

    for (size_t i = 2; i < LIMIT_PRIME_N; ++i) {
        if (primes[i] == true) {
            for (size_t j = 2; j * i < LIMIT_PRIME_N; ++j) {
                primes[i * j] = false;
            }
        }
    }
}
