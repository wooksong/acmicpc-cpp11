#include <iostream>
#include <vector>

int main() {
    uint32_t N, K, cnt;
    std::cin >> N >> K;
    std::vector<bool> divisors = std::vector<bool>(N + 1, false);

    cnt = 0;
    for (uint32_t i = 1; i < N + 1; ++i) {
        if (N % i == 0) {
            divisors[i] = true;
            cnt++;
        }

        if (cnt == K) {
            printf("%u\n", i);
            break;
        }
    }

    if (cnt < K) {
        printf("%u\n", 0U);
    }

    return 0;
}
