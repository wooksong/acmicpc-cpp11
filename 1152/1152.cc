#include <iostream>

int main() {
    std::string word;
    uint32_t cnt = 0;

    // freopen("input.txt", "r", stdin);

    while (std::cin >> word) {
        cnt++;
    }

    std::cout << cnt << "\n";
}
