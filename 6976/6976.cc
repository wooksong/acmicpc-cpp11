#include <iostream>

void sub(std::string &big, std::string small);
static inline uint32_t to_uint32(char c) {
    return static_cast<uint32_t>(c - '0');
}
int main() {
    uint32_t T, num, mul;
    std::string long_digits;
    std::string msg;

    // freopen("input.txt", "r", stdin);
    std::cin >> T;

    for (uint32_t i = 0; i < T; ++i) {
        std::cin >> long_digits;
        msg = "The number " + long_digits + " is ";

        while (long_digits.length() > 2) {
            std::string small =
                std::string(long_digits, long_digits.length() - 1, 1);
            std::cout << long_digits << "\n";
            long_digits.pop_back();
            sub(long_digits, small);

            for (auto iter = long_digits.begin(); iter != long_digits.end();
                 ++iter) {
                if (*iter == '0')
                    long_digits.erase(iter);
                break;
            }
        }

        num = 0;
        mul = 1;
        for (auto iter = long_digits.begin(); iter != long_digits.end();
             ++iter, mul *= 10) {
            num *= mul;
            num += (*iter - '0');
        }

        std::cout << long_digits << "\n";
        if ((num % 11) == 0) {
            msg.append("divisible by 11.\n\n");
        } else {
            msg.append("not divisible by 11.\n\n");
        }
        std::cout << msg;
        msg.clear();
    }

    return 0;
}

void sub(std::string &big, std::string small) {
    uint32_t carry = 0;
    size_t ridx = big.length() - 1;

    for (auto iter = small.rbegin(); iter != small.rend(); ++iter) {
        uint32_t minuend = to_uint32(big.at(ridx));
        uint32_t substrahend = to_uint32(*iter);
        uint32_t ans = 0;

        if (minuend < substrahend + carry) {
            ans = 10 + minuend - substrahend - carry;
            carry = 1;
        } else {
            ans = minuend - substrahend - carry;
            carry = 0;
        }
        big[ridx] = '0' + static_cast<char>(ans - 0);
        ridx--;
    }

    for (int32_t i = ridx; carry != 0 && i >= 0; --i) {
        uint32_t minuend = to_uint32(big.at(i));
        uint32_t ans = 0;

        if (minuend < carry) {
            ans = 10 + minuend - carry;
            carry = 1;
        } else {
            ans = minuend - carry;
            carry = 0;
        }
        big[i] = '0' + static_cast<char>(ans - 0);
    }
}
