#include <iostream>
#include <memory.h>

constexpr int MAX_LEN = 101;
int main() {
    uint32_t N, sum;
    char num[MAX_LEN];

    memset(num, '\0', MAX_LEN);
    std::cin >> N;
    std::cin >> num;

    sum = 0;
    for (uint32_t i = 0; i < N; ++i) {
        sum += (num[i] - '0');
    }

    printf("%u\n", sum);

    return 0;
}
