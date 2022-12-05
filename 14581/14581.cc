#include <iostream>

constexpr int NUM_REPEATS = 3;

int main() {
    const std::string emoji_fan = ":fan:";
    std::string emoji_id = ":";
    std::string id;

    // freopen("input.txt", "r", stdin);
    std::cin >> id;
    emoji_id += id;
    emoji_id += ":";

    for (int i = 0; i < NUM_REPEATS; ++i) {
        for (int j = 0; j < NUM_REPEATS; ++j) {
            if (i == 1 && j == 1) {
                std::cout << emoji_id;
            } else {
                std::cout << emoji_fan;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
