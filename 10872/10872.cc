#include <iostream>

uint32_t fact(uint32_t n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    uint32_t N;

    std::cin >> N;

    printf("%u\n", fact(N));

    return 0;
}
