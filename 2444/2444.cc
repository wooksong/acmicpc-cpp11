#include <iostream>

int main() {
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        int num_stars = 2 * i - 1;
        int num_blanks = N - i;

        for (int j = 0; j < num_blanks; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < num_stars; ++j) {
            std::cout << "*";
        }

        std::cout << "\n";
    }
    for (int i = N - 1; i > 0; --i) {
        int num_stars = 2 * i - 1;
        int num_blanks = N - i;

        for (int j = 0; j < num_blanks; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < num_stars; ++j) {
            std::cout << "*";
        }

        std::cout << "\n";
    }
    return 0;
}
