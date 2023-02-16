#include <iostream>

int main() {
    std::string binary;
    std::string octet;
    size_t len;

    int num;

    // freopen("input.txt", "r", stdin);

    std::cin >> binary;

    len = binary.length();
    num = 0;
    for (size_t i = 1, mul = 1; i <= len; ++i) {
        num += (static_cast<int>(*(binary.rbegin() + i - 1) - '0') * mul);
        mul *= 2;
        if (i % 3 == 0) {
            octet.append(std::to_string(num));
            num = 0;
            mul = 1;
        }
    }

    octet.append(std::to_string(num));
    {
        size_t pos = 0;
        std::string ret;

        for (auto iter = octet.rbegin(); iter != octet.rend(); ++iter) {
            ret.push_back(*iter);
        }

        while (ret[pos] == '0') {
            pos++;
        }

        octet = ret.substr(pos);
        std::cout << (octet.empty() ? "0" : ret.substr(pos)) << "\n";
    }

    return 0;
}
