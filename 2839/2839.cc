// Greedy approach version
#include <iostream>

constexpr int32_t WEIGHT_BIG = 5;
constexpr int32_t WEIGHT_SMALL = 3;

int main() {
    int32_t N, min, num_bigs, num_smalls;

    std::cin >> N;

    min = INT32_MAX;
    if (N % WEIGHT_BIG == 0) {
        std::cout << N / WEIGHT_BIG << "\n";
        return 0;
    } else if (N % WEIGHT_SMALL == 0) {
        min = N / WEIGHT_SMALL;
    }

    num_bigs = N / WEIGHT_BIG;
    num_smalls = -1;
    while (num_bigs > 0) {
        int32_t remainder = N - num_bigs * WEIGHT_BIG;

        if (remainder % WEIGHT_SMALL == 0) {
            num_smalls = remainder / WEIGHT_SMALL;
            min = std::min(min, num_bigs + num_smalls);
        }
        --num_bigs;
    }

    if (num_smalls == -1 && min == INT32_MAX) {
        std::cout << "-1\n";
    } else {
        std::cout << min << "\n";
    }
    return 0;
}
