#include <iostream>

int main() {
    int N, len;

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    std::cin >> N;

    len = 2 * N - 1;

    for (int i = 1; i <= N; ++i) {
        int num_stars = i * 2 - 1;

        for (int j = 0; j < (len - num_stars) / 2; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < num_stars; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
