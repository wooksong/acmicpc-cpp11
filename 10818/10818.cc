#include <iostream>

using namespace std;

uint32_t numbers[1000000];

int main() {
    int N;
    int max = -1000000;
    int min = 1000000;

    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;

        cin >> tmp;
        if (tmp <= min) {
            min = tmp;
        }
        if (tmp >= max) {
            max = tmp;
        }
        numbers[i] = tmp;
    }
    printf("%d %d\n", min, max);

    return 0;
}
