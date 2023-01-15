#include <iostream>

constexpr int NUM_STOPS = 4;

int main() {
    int max_num_guests = INT32_MIN;
    int num_guests = 0;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    for (int i = 0; i < NUM_STOPS; ++i) {
        int out, in;

        std::cin >> out >> in;
        num_guests -= out;
        num_guests += in;

        if (num_guests > max_num_guests) {
            max_num_guests = num_guests;
        }
    }

    std::cout << max_num_guests << "\n";

    return 0;
}
