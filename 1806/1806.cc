#include <iostream>
#include <vector>

int main() {
    int min_len = INT32_MAX;
    int len_v;
    int sum_tgt;
    int i, j, sum;

    // freopen("input.txt", "r", stdin);
    std::cin >> len_v >> sum_tgt;

    std::vector<int> nums(len_v);
    for (i = 0; i < len_v; ++i) {
        std::cin >> nums[i];
    }

    i = 0;
    j = 0;

    sum = nums[i];
    while (i < len_v && j < len_v) {
        if (sum >= sum_tgt) {
            min_len = std::min(min_len, j - i + 1);
        }
        if (sum < sum_tgt) {
            sum += nums[++j];
        } else {
            sum -= nums[i++];
        }
    }

    std::cout << (min_len == INT32_MAX ? 0 : min_len) << "\n";

    return 0;
}
