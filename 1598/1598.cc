#include <iostream>

constexpr int NUM_CNTS = 2;
struct num_t {
    uint32_t val;
    uint32_t m;
    uint32_t n;
};

void calc_coord(uint32_t n, struct num_t &num);

int main() {
    struct num_t nums[NUM_CNTS];
    uint32_t len = 0;
    for (int i = 0; i < NUM_CNTS; ++i) {
        std::cin >> nums[i].val;
        calc_coord(nums[i].val, nums[i]);
    }

    if (nums[0].m > nums[1].m) {
        len += (nums[0].m - nums[1].m);
    } else {
        len += (nums[1].m - nums[0].m);
    }

    if (nums[0].n > nums[1].n) {
        len += (nums[0].n - nums[1].n);
    } else {
        len += (nums[1].n - nums[0].n);
    }

    printf("%u\n", len);
    return 0;
}

void calc_coord(uint32_t n, struct num_t &num) {
    num.m = (n % 4);
    if (num.m == 0) {
        num.m = 3;
    } else {
        num.m -= 1;
    }
    num.n = n / 4;
    if (num.m == 3) {
        num.n -= 1;
    }
}
