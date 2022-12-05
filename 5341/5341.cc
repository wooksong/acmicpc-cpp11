#include <iostream>

int main() {
    int n;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        int sum;

        std::cin >> n;
        if (n == 0) {
            break;
        }

        sum = 0;
        for (int i = n; i > 0; --i) {
            sum += i;
        }

        std::cout << sum << "\n";
    }
    return 0;
}
