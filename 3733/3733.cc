#include <iostream>

int main() {
    int N, S;

    // freopen("input.txt", "r", stdin);
    while (std::cin >> N >> S) {
        std::cout << S / (N + 1) << "\n";
    }

    return 0;
}
