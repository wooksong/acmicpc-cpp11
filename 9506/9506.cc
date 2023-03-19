#include <bitset>
#include <iostream>
#include <vector>

constexpr size_t MAX_N = 100001;

int main() {
    std::vector<size_t> proper_divisors;
    std::bitset<MAX_N> divisors;
    size_t n;

    // freopen("input.txt", "r", stdin);

    proper_divisors.reserve(MAX_N);
    do {
        size_t sum;

        std::cin >> n;
        if (n == SIZE_MAX) {
            break;
        }
        proper_divisors.clear();
        divisors.reset();

        for (size_t i = 1; i <= n; ++i) {
            size_t pair;

            if (n % i != 0) {
                continue;
            }

            pair = n / i;
            if (divisors.test(i) || divisors.test(pair)) {
                break;
            }
            divisors.set(i);
            divisors.set(pair);
        }
        sum = 0;
        for (size_t i = 1; i < n; ++i) {
            if (divisors.test(i)) {
                sum += i;
                proper_divisors.push_back(i);
            }
        }

        if (sum == n) {
            size_t len = proper_divisors.size() - 1;

            std::cout << n << " = ";
            for (size_t i = 0; i < len; ++i) {
                std::cout << proper_divisors[i] << " + ";
            }
            std::cout << proper_divisors.back() << "\n";
        } else {
            std::cout << n << " is NOT perfect.\n";
        }
    } while (true);

    return 0;
}
