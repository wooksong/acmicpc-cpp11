#include <iostream>

constexpr uint32_t LIMIT_NUM = 10001;

uint32_t nums[LIMIT_NUM];

int main() {
    uint32_t N, i;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (i = 1; i < LIMIT_NUM; ++i) {
        nums[i] = 0;
    }

    for (i = 1; i <= N; ++i) {
        uint32_t num;

        std::cin >> num;
        nums[num]++;
    }
    for (i = 1; i < LIMIT_NUM; ++i) {
        uint32_t cnt = nums[i];

        for (uint32_t j = 0; j < cnt; ++j) {
            std::cout << i << "\n";
        }
    }

    return 0;
}
