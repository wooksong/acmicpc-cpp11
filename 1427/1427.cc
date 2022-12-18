#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<size_t> num;
    std::string N;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (char c : N) {
        num.push_back(static_cast<int>(c - '0'));
    }

    std::sort(num.begin(), num.end(), std::greater<int>());
    for (int i : num) {
        std::cout << i;
    }
    std::cout << "\n";

    return 0;
}
