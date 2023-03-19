#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<char>> table;
    std::string res = "";
    std::string encoded;
    size_t K, n_rows, i, j;
    bool backward = false;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> K;
    std::cin >> encoded;

    n_rows = encoded.length() / K;
    table = std::vector<std::vector<char>>(n_rows, std::vector<char>(K));

    i = 0;
    j = 0;
    for (char c : encoded) {
        table[i][j] = c;

        (backward ? j-- : j++);

        if (j == K || j == SIZE_MAX) {
            if (j == K) {
                j = K - 1;
                backward = true;
            } else {
                j = 0;
                backward = false;
            }

            i++;
        }
    }

    for (i = 0; i < K; ++i) {
        for (j = 0; j < n_rows; ++j) {
            res += table[j][i];
        }
    }
    std::cout << res << "\n";

    return 0;
}
