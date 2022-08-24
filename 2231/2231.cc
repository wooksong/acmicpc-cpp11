#include <iostream>

int main() {
    uint32_t N, M, i, sum;

    std::cin >> N;

    M = 0;
    sum = 0;
    for (i = 1; i < N; ++i) {
        uint32_t tmp = i;

        sum = i;
        while (tmp != 0) {
            sum += (tmp % 10);
            tmp /= 10;
        }
        if (N == sum) {
            M = i;
            break;
        }
    }

    std::cout << M << "\n";

    return 0;
}
