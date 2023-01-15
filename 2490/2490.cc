#include <iostream>

const std::string results[] = {"E", "A", "B", "C", "D"};
const int NUM_TRIES = 3;
const int NUM_BARS = 4;

int main() {
    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < NUM_TRIES; ++i) {
        int num_zeors = 0;

        for (int j = 0; j < NUM_BARS; ++j) {
            int r;

            std::cin >> r;
            if (!r) {
                num_zeors++;
            }
        }

        std::cout << results[num_zeors] << "\n";
    }
    return 0;
}
