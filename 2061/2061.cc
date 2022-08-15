#include <iostream>
#include <vector>

void eratosthenes_sieve(uint32_t N, std::vector<uint32_t> &primes) {
    std::vector<uint32_t> v = std::vector<uint32_t>(N, 1);

    for (size_t i = 2; i < v.size(); ++i) {
        size_t j = 2;
        while (i * j < v.size()) {
            v[i * j++] = 0;
        }
    }

    for (size_t i = 2; i < v.size(); ++i) {
        if (v[i] == 1) {
            primes.push_back(i);
        }
    }
}

int main() {
    std::string K;
    size_t L;
    std::vector<uint32_t> prime_numbers;

    std::cin >> K >> L;
    eratosthenes_sieve(L, prime_numbers);

    for (uint32_t p : prime_numbers) {
        uint32_t mod, tmp;

        mod = 0;
        tmp = 1;

        for (auto iter = K.rbegin(); iter != K.rend(); ++iter) {
            mod = (mod + (*iter - '0') * tmp) % p;
            tmp *= 10;
            tmp %= p;
        }

        if (mod == 0) {
            printf("BAD %u\n", p);
            return 0;
        }
    }

    printf("GOOD\n");

    return 0;
}
