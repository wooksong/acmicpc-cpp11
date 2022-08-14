#include <iostream>

constexpr int MAX_N = 10000;

int main() {
    int N, X;
    int seq[MAX_N];

    std::cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        std::cin >> seq[i];
        if (seq[i] < X) {
            printf("%d ", seq[i]);
        }
    }

    printf("\n");

    return 0;
}
