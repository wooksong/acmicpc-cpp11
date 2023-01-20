#include <cmath>
#include <iostream>

int main() {
    std::string num_plate;
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        std::cin >> num_plate;

        {
            std::string front = num_plate.substr(0UL, 3UL);
            std::string back = num_plate.substr(4UL, 4UL);
            int val_front = 0;
            int val_back = 0;
            int j;

            j = 1;
            for (auto c = front.rbegin(); c != front.rend(); ++c) {
                val_front += (static_cast<int>(*c - 'A') * j);
                j *= 26;
            }

            j = 1;
            for (auto c = back.rbegin(); c != back.rend(); ++c) {
                val_back += (static_cast<int>(*c - '0') * j);
                j *= 10;
            }

            if (std::abs(val_front - val_back) > 100) {
                std::cout << "not nice\n";
            } else {
                std::cout << "nice\n";
            }
        }
    }
    return 0;
}
