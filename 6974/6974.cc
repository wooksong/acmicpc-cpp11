#include <iostream>

int32_t compare_lt(std::string left, std::string right);
void sub(std::string &left, std::string right);

int main() {
    uint32_t n;
    std::string dividend;
    std::string divisor;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    std::cin >> n;
    for (uint32_t i = 0; i < n; ++i) {
        int32_t cmp;
        uint32_t q;
        std::cin >> dividend;
        std::cin >> divisor;

        cmp = compare_lt(dividend, divisor);
        if (cmp == 0) {
            std::cout << "1\n0\n\n";
            continue;
        } else if (cmp < 0) {
            std::cout << "0\n" << dividend << "\n\n";
            continue;
        }
        q = 0;
        while (cmp > 0) {
            sub(dividend, divisor);
            q++;
            cmp = compare_lt(dividend, divisor);
        }

        switch (cmp) {
        case 0:
            std::cout << q + 1 << "\n0\n\n";
            break;
        case -1:
            std::cout << q << "\n" << dividend << "\n\n";
            break;
        default:
            break;
        }
    }
    return 0;
}

int32_t compare_lt(std::string left, std::string right) {
    size_t len_l = left.length(), len_r = right.length();

    if (left == right) {
        return 0;
    }
    if (len_l > len_r) {
        return 1;
    } else if (len_l < len_r) {
        return -1;
    } else {
        size_t i = 0;
        for (auto iter = left.begin(); iter != left.end(); ++iter, ++i) {
            uint32_t l = static_cast<uint32_t>(*iter - '0');
            uint32_t r = static_cast<uint32_t>(right.c_str()[i] - '0');

            if (l > r)
                return 1;
            if (r > l)
                return -1;
        }

        return 0;
    }
}

void sub(std::string &left, std::string right) {
    for (auto iter_r = right.rbegin(), iter_l = left.rbegin();
         iter_r != right.rend(); ++iter_r, ++iter_l) {
        int32_t l = *iter_l - '0';
        int32_t r = *iter_r - '0';

        if (l >= r) {
            *iter_l = (l - r) + '0';
        } else {
            *iter_l = (10 + l - r) + '0';
            for (auto iter = iter_l + 1; iter != left.rbegin(); ++iter) {
                int32_t next_digit = *iter - '0';

                next_digit -= 1;
                if (next_digit < 0) {
                    next_digit += 10;
                    *iter = next_digit + '0';
                } else {
                    *iter = next_digit + '0';
                    break;
                }
            }
        }
    }

    size_t start = left.find_first_not_of("0");
    if (start != 0)
        left = left.substr(start);
}
