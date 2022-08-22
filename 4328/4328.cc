#include <iostream>

uint32_t to_decimal_num(uint32_t b, std::string num);
uint32_t calc_mod_of(uint32_t b, std::string num, uint32_t m);
std::string to_base_n_num(uint32_t b, uint32_t num);

int main() {
    uint32_t b;
    std::string p, m;

    while (true) {
        uint32_t dec_m;

        std::cin >> b;

        if (b == 0)
            return 0;
        std::cin >> p >> m;
        dec_m = to_decimal_num(b, m);

        std::cout << to_base_n_num(b, calc_mod_of(b, p, dec_m)) << "\n";
    }

    return 0;
}

uint32_t to_decimal_num(uint32_t b, std::string num) {
    uint32_t res = 0;
    uint32_t exp = 1;

    for (auto iter = num.rbegin(); iter != num.rend(); ++iter) {
        res = res + exp * static_cast<uint32_t>(*iter - '0');
        exp *= b;
    }

    return res;
}

uint32_t calc_mod_of(uint32_t b, std::string p, uint32_t m) {
    uint32_t res = 0;
    for (auto iter = p.begin(); iter != p.end(); ++iter) {
        res = (res * b + *iter - '0') % m;
    }

    return res;
}

std::string to_base_n_num(uint32_t b, uint32_t num) {
    std::string res;

    while (num >= b) {
        res.insert(0, std::to_string(num % b));
        num /= b;
    }

    res.insert(0, std::to_string(num));
    return res;
}
