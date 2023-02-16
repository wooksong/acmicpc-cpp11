#include <iostream>
#include <unordered_map>

const std::unordered_map<int, int> DAYS_IN_MON = {
    {4, 30}, {6, 30}, {9, 30}, {11, 30}, {1, 31},  {2, 28},
    {3, 31}, {5, 31}, {7, 31}, {8, 31},  {10, 31}, {12, 31},
};

int main() {
    int m, d;
    int num_days;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> m >> d;

    num_days = 0;
    for (int i = 1; i < m; ++i) {
        num_days += DAYS_IN_MON.at(i);
    }

    num_days += d;

    switch (num_days % 7) {
    case 1:
        std::cout << "MON\n";
        break;
    case 2:
        std::cout << "TUE\n";
        break;
    case 3:
        std::cout << "WED\n";
        break;
    case 4:
        std::cout << "THU\n";
        break;
    case 5:
        std::cout << "FRI\n";
        break;
    case 6:
        std::cout << "SAT\n";
        break;
    default:
        std::cout << "SUN\n";
        break;
    }

    return 0;
}
