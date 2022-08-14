#include <iostream>

using namespace std;

int main() {
    uint32_t N;

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (uint32_t i = 1; i <= N; ++i) {
        for (uint32_t j = 0; j < i; ++j)
            printf("*");
        printf("\n");
    }
}
