#include <array>
#include <iostream>

constexpr size_t MAX_N = 100001;

std::array<bool, MAX_N> nums;

int main() {
    int max = INT32_MIN;
    int small, large;
    int sum;

    freopen("input.txt", "r", stdin);
    std::cin >> small >> large;

    std::fill_n(nums.begin(), MAX_N, true);
    nums[1] = false;

    for (int i = 2; i <= large; ++i) {
        for (int j = 2; i * j <= large; ++j) {
            nums[i * j] = false;
        }
    }

    sum = 0;
    for (int i = small; i <= large; ++i) {
        if (nums[i]) {
            sum += i;
            max = std::max(max, i);
        }
    }

    if (!sum) {
        std::cout << "-1\n";
    } else {
        std::cout << sum << "\n";
        std::cout << max << "\n";
    }

    return 0;
}
