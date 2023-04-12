#include <iostream>

uint64_t cal_fact(uint64_t num);

int main() {
    uint64_t N;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;

    std::cout << cal_fact(N) << "\n";

    return 0;
}

uint64_t cal_fact(uint64_t num) {
    if (num == 0)
        return 1;

    return cal_fact(num - 1) * num;
}
