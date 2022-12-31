#include <iostream>

int main() {
    std::string stars;
    size_t len;

    // freopen("input.txt", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> len;
    stars = std::string(len, '*');
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < i; ++j) {
            std::cout << " ";
        }
        std::cout << &stars[i] << "\n";
    }

    return 0;
}
