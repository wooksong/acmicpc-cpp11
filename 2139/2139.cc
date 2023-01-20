#include <iostream>

const int days_in_a_mon[] = {
    -1,
    31, // 1
    28, // 2
    31, // 3
    30, // 4
    31, // 5
    30, // 6
    31, // 7
    31, // 8
    30, // 9
    31, // 10
    30, // 11
    31, // 12
};

int main() {
    int y, m, d;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        int num_days;
        bool is_leap_y;

        std::cin >> d >> m >> y;

        if ((d == 0) && (m == 0) && (y == 0)) {
            break;
        }
        is_leap_y = false;
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
            is_leap_y = true;
        }

        num_days = 0;
        for (int i = 1; i < m; ++i) {
            num_days += days_in_a_mon[i];
        }
        if (m > 2 && is_leap_y) {
            num_days++;
        }
        num_days += d;

        std::cout << num_days << "\n";
    }

    return 0;
}
