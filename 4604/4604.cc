#include <iostream>

char decode(uint32_t bin);

int main() {
    std::string p_text;
    std::string code;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    while (std::getline(std::cin, p_text)) {
        int cnt = 0;

        if (p_text == "#")
            break;
        for (auto iter = p_text.begin(); iter != p_text.end(); ++iter) {
            if (*iter == '*') {
                size_t i;
                uint32_t binary = 0x0U;

                for (i = 0; i < code.length(); ++i, binary <<= 1) {
                    if (code[i] == '1') {
                        binary |= 0x1U;
                    }

                    if ((i + 1 >= 5) && ((i + 1) % 5 == 0)) {
                        std::cout << decode(binary);
                        binary = 0x0U;
                    }
                }

                while (((i + 1) % 5) != 0) {
                    ++i;
                    binary <<= 1;
                }

                if (binary != 0)
                    std::cout << decode(binary);
                std::cout << "\n";

                code.clear();
                break;
            } else if (*iter != ' ') {
                if (cnt != 0) {
                    if ((cnt % 2) == 0) {
                        code.append("1");
                    } else {
                        code.append("0");
                    }
                    cnt = 0;
                }
            } else {
                ++cnt;
            }
        }
    }

    return 0;
}

char decode(uint32_t bin) {
    switch (bin) {
    case 0:
        return ' ';
    case 27:
        return '\'';
    case 28:
        return ',';
    case 29:
        return '-';
    case 30:
        return '.';
    case 31:
        return '?';
    default:
        return 'A' + static_cast<uint8_t>(bin - 1);
    }
}
