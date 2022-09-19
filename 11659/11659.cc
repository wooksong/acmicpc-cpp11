#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::vector<int> nums;
    std::vector<int64_t> sums;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    std::cin >> N >> M;

    nums = std::vector<int>(N);
    sums = std::vector<int64_t>(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
        if (i == 0) {
            sums[i] = nums[i];
        } else {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    for (int i = 0; i < M; ++i) {
        int from, to;

        std::cin >> from >> to;
        if (from == to) {
            std::cout << nums[from - 1];
        } else if (from == 1) {
            std::cout << sums[to - 1];
        } else {
            std::cout << sums[to - 1] - sums[from - 2];
        }
        std::cout << "\n";
    }

    return 0;
}
