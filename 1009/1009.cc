#include <iostream>

int main() {
    uint32_t a, b, T;
    uint32_t mul;

    // freopen("input.txt", "r", stdin);
    std::cin >> T;
    for (uint32_t t = 0; t < T; ++t) {
        mul = 1;
        std::cin >> a >> b;
        for (uint32_t i = 0; i < b; ++i) {
            mul *= (a % 10);
            mul %= 10;
        }

        if (mul == 0) {
            mul = 10;
        }

        std::cout << mul << "\n";
    }

    return 0;
}
