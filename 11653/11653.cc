#include <iostream>
#include <vector>

int main() {
    std::vector<size_t> nums;
    size_t N;
    size_t tmp;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin >> N;

    if (N == 1)
        return 0;

    nums = std::vector<size_t>(N + 1, 1);

    tmp = N;
    for (size_t i = 2; i <= N; ++i) {
        if (nums[i]) {
            while ((tmp % i) == 0) {
                std::cout << i << "\n";
                tmp /= i;
            }
        }
    }
    return 0;
}
