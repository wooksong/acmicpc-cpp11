#include <iostream>

bool check(int num);
int main() {
    int num;

    std::cin >> num;
    std::cout << (check(num) ? "YES" : "NO") << "\n";
    return 0;
}

bool check(int num) {
    int dividend = num;
    int r;

    if (!num)
        return false;

    while (dividend > 0) {
        r = dividend % 3;
        if (r > 1)
            return false;
        dividend /= 3;
    }

    return true;
}
