#include <iostream>
#include <memory.h>

constexpr uint64_t MAX_LEN = 51;
constexpr uint64_t R = 31;
constexpr uint64_t M = 1234567891;

int main() {
    uint64_t L;
    char buf[MAX_LEN];
    uint64_t hash = 0;
    uint64_t mul = 1;

    std::cin >> L;
    std::cin.ignore();
    std::cin.getline(buf, L + 1);

    for (uint64_t i = 0; i < L; ++i) {
        hash += (mul * static_cast<uint64_t>(buf[i] - 'a' + 1)) % M;
        mul *= R;
        mul %= M;
    }
    hash %= M;

    std::cout << hash << "\n";
    return 0;
}
