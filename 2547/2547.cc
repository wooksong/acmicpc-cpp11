#include <iostream>

uint64_t calc_mod_of(std::string p, uint64_t q);
int main() {
    uint64_t T, N, sum;
    std::string nums_candy;

    // freopen("input.txt", "r", stdin);
    std::cin >> T;
    for (uint64_t i = 0; i < T; ++i) {
        std::getline(std::cin, nums_candy);
        sum = 0;
        std::cin >> N;
        for (uint64_t j = 0; j < N; ++j) {
            std::cin >> nums_candy;
            sum += calc_mod_of(nums_candy, N);
        }
        if ((sum % N) == 0) {
            std::cout << "YES\n";
            continue;
        }
        std::cout << "NO\n";
    }
}

uint64_t calc_mod_of(std::string p, uint64_t q) {
    uint64_t res = 0;

    for (auto iter = p.begin(); iter != p.end(); ++iter) {
        res = (res * 10 + *iter - '0') % q;
    }

    return res;
}
