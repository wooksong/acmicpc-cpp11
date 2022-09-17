#include <iostream>

typedef long long ll_t;

bool check(ll_t num);
int main() {
    ll_t num;

    std::cin >> num;
    std::cout << (check(num) ? "YES" : "NO") << "\n";
    return 0;
}

bool check(ll_t num) {
    ll_t dividend = num;
    ll_t r;

    if (!num)
        return false;

    while (dividend > 0) {
        r = dividend % 3LL;
        if (r > 1LL)
            return false;
        dividend /= 3LL;
    }

    return true;
}
