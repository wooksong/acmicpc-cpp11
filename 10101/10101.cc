#include <iostream>
#include <vector>

constexpr int NUM_ANGLES = 3;
constexpr int SUM_ANGLES = 180;
constexpr int ANGLE_EQUILATERAL = 60;

int main() {
    std::vector<int> angles(NUM_ANGLES);
    int sum = 0;

    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < NUM_ANGLES; ++i) {
        int angle;

        std::cin >> angle;

        angles[i] = angle;
        sum += angle;
    }

    if (sum != SUM_ANGLES) {
        std::cout << "Error\n";
        return 0;
    }

    {
        bool equil = true;

        for (int i = 0; i < NUM_ANGLES; ++i) {
            if (angles[i] != ANGLE_EQUILATERAL) {
                equil = false;
                break;
            }
        }

        if (equil) {
            std::cout << "Equilateral\n";
            return 0;
        }
    }

    if (angles[0] == angles[1] || angles[1] == angles[2] ||
        angles[0] == angles[2]) {
        std::cout << "Isosceles\n";
    } else {
        std::cout << "Scalene\n";
    }

    return 0;
}
