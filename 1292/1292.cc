#include <iostream>

int main() {
    int A, B, cnt, sum;

    // freopen("input.txt", "r", stdin);
    std::cin >> A >> B;
    cnt = 0;
    sum = 0;
    for (int i = 1; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            cnt++;
            sum += i;

            if (cnt == A) {
                sum = i;
            }
            if (cnt == B) {
                break;
            }
        }
        if (cnt == B) {
            break;
        }
    }
    std::cout << sum << "\n";

    return 0;
}
