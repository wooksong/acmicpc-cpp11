#include <iostream>

constexpr int MAX_SIZE = 51;
uint32_t ractangle[MAX_SIZE][MAX_SIZE];

int main() {
    int i, j, k, N, M;
    uint32_t edge, max;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;
    for (i = 0; i < N; ++i) {
        std::string line;

        std::cin >> line;
        for (j = 0; j < M; ++j) {
            ractangle[i][j] = static_cast<uint32_t>(line[j] - '0');
        }
    }

    edge = std::min(N, M);
    max = 1;
    for (i = edge; i > 0; --i) {
        for (j = 0; j < N - i; ++j) {
            for (k = 0; k < M - i; ++k) {
                if ((ractangle[j][k] == ractangle[j][k + i]) &&
                    (ractangle[j][k + i] == ractangle[j + i][k]) &&
                    (ractangle[j + i][k] == ractangle[j + i][k + i])) {
                    uint32_t area = (i + 1) * (i + 1);

                    if (area > max) {
                        max = area;
                        goto ret_print_max;
                    }
                }
            }
        }
    }

ret_print_max:
    std::cout << max << "\n";

    return 0;
}
