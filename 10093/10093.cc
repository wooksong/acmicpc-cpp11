#include <iostream>

int main() {
    uint64_t A, B;

    std::cin >> A >> B;
    if (A == B) {
        std::cout << "0\n";
        return 0;
    } else if (A < B) {
        std::swap(A, B);
    }

    if ((A - B) == 1) {
        std::cout << "0\n";
        return 0;
    }
    std::cout << A - (B + 1) << "\n";
    for (uint64_t i = B + 1; i < A; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
