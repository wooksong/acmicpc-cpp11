#include <iostream>

int main() {
    int t, is_w_alcohol;

    std::cin >> t >> is_w_alcohol;

    if (is_w_alcohol || (t < 12 || t > 16)) {
        std::cout << "280\n";
    } else {
        std::cout << "320\n";
    }
    return 0;
}
