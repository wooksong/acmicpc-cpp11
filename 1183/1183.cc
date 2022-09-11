#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int32_t> sums;
    int N;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;

    sums = std::vector<int32_t>(N, 0);

    for (int i = 0; i < N; ++i) {
        int32_t A, B;

        std::cin >> A >> B;
        sums[i] = (A - B);
    }

    std::sort(sums.begin(), sums.end());

    if ((sums.size() % 2) == 1) {
        std::cout << "1\n";
    } else {
        std::cout << std::abs(sums[N / 2] - sums[N / 2 - 1]) + 1 << "\n";
    }
    return 0;
}
