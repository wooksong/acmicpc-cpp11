#include <iostream>
#include <vector>

int main() {
    std::vector<int> codes;
    size_t pos_key;
    size_t len_key;
    std::string text;
    std::string key;
    std::string enc;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::getline(std::cin, text);
    std::cin >> key;

    len_key = key.length();
    pos_key = 0;
    for (char c : text) {
        int code;

        code = static_cast<int>(c - 'a');
        if (c != ' ') {
            code -= static_cast<int>(key[pos_key] - 'a');

            if (code <= 0) {
                code += static_cast<int>('z' - 'a') + 1;
            }
        }
        codes.push_back(code);
        pos_key++;
        pos_key %= len_key;
    }

    for (int c : codes) {
        if (c == -65) {
            enc.push_back(' ');
            continue;
        }
        enc.push_back(static_cast<char>('a' + c - 1));
    }

    std::cout << enc << "\n";

    return 0;
}
