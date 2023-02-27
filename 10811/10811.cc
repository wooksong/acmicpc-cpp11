#include <iostream>
#include <vector>

int main() {
    std::vector<size_t> nums;
    size_t N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N >> M;
    nums.reserve(N);

    for (size_t pos = 1; pos <= N; ++pos) {
        nums.push_back(pos);
    }

    for (size_t m = 0; m < M; ++m) {
        size_t i, j;
        size_t len;

        std::cin >> i >> j;

        len = j - i;
        for (size_t dis = 0; dis < len; ++dis) {
            size_t pos = i + dis - 1;
            size_t back_pos = j - dis - 1;

            if (back_pos <= pos) {
                break;
            } else {
                std::swap(nums[pos], nums[back_pos]);
            }
        }
    }

    for (size_t n : nums) {
        std::cout << n << " ";
    }
    std::cout << "\n";

    return 0;
}
