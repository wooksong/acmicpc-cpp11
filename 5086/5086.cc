#include <iostream>

int main() {
    int left, right;

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    while (true) {
        std::cin >> left >> right;

        if (left == 0 && right == 0) {
            break;
        }

        if (right > left && right % left == 0) {
            std::cout << "factor\n";
        } else if (left > right && left % right == 0) {
            std::cout << "multiple\n";
        } else {
            std::cout << "neither\n";
        }
    }

    return 0;
}
