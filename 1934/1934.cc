#include <iostream>

int calc_gcd(int big, int small) {
    if (small > big) {
        std::swap(big, small);
    }

    if (big % small == 0) {
        return small;
    }

    return calc_gcd(small, big % small);
}

int calc_lcm(int l, int r, int gcd) { return l * r / gcd; }

int main() {
    int T;
    int A, B;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> T;
    while (T--) {
        int gcd;

        std::cin >> A >> B;
        gcd = calc_gcd(A, B);
        std::cout << calc_lcm(A, B, gcd) << "\n";
    }
    return 0;
}
