#include <iostream>

int main() {
    uint64_t n, n_runs;

    std::cin >> n;
    n_runs = 0;

    for (uint64_t i = n - 1; i != 0; --i) {
        n_runs += i;
    }

    std::cout << n_runs << "\n";
    std::cout << "2\n";

    return 0;
}
