#include <iostream>

constexpr int NUM_N = 7;

int main() {
    int sum;
    int min_odd = INT32_MAX;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    sum = 0;
    for (int i = 0; i < NUM_N; ++i) {
        int n;

        std::cin >> n;
        if (n % 2 == 0)
            continue;

        sum += n;
        if (n < min_odd) {
            min_odd = n;
        }
    }

    if (min_odd == INT32_MAX) {
        std::cout << "-1\n";
    } else {
        std::cout << sum << "\n";
        std::cout << min_odd << "\n";
    }

    return 0;
}
