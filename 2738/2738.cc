#include <iostream>

using namespace std;

constexpr int maxN = 100;
constexpr int maxM = 100;

int main()
{
    uint32_t N, M;
    uint32_t matrix[maxN][maxM];

    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (uint32_t i = 0; i < N; ++i) {
        for (uint32_t j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (uint32_t i = 0; i < N; ++i) {
        for (uint32_t j = 0; j < M; ++j) {
            uint32_t tmp;

            cin >> tmp;
            matrix[i][j] += tmp;
            printf("%u ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
