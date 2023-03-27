#include <iostream>
#include <vector>

constexpr size_t NUM_SIDES = 3;

int main() {
    std::vector<int> sides(NUM_SIDES, -1);

    freopen("input.txt", "r", stdin);

    while (sides[0] != 0 && sides[1] != 0 && sides[2] != 0) {
        size_t longest_idx = 0;
        int sum_others = 0;

        std::cin >> sides[longest_idx];
        sum_others += sides[0];
        for (size_t i = 1; i < NUM_SIDES; ++i) {
            std::cin >> sides[i];

            if (sides[i] > sides[longest_idx]) {
                longest_idx = i;
            }

            sum_others += sides[i];
        }

        if (sides[0] == 0) {
            continue;
        }

        sum_others -= sides[longest_idx];
        if ((sum_others - sides[longest_idx]) <= 0) {
            std::cout << "Invalid\n";
        } else if (sides[0] == sides[1] && sides[1] == sides[2]) {
            std::cout << "Equilateral\n";
        } else if (sides[0] == sides[1] || sides[0] == sides[2] ||
                   sides[1] == sides[2]) {
            std::cout << "Isosceles\n";
        } else {
            std::cout << "Scalene\n";
        }
    }

    return 0;
}
