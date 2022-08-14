#include <iostream>

constexpr int MAX_LEN = 256;

int main() {
    char input[MAX_LEN];
    std::string aeiou = std::string("aeiouAEIOU");

    // freopen("input.txt", "r", stdin);

    while (std::cin.getline(input, MAX_LEN, '\n')) {
        std::string line;
        size_t cnt = 0;

        if (input[0] == '#') {
            break;
        }

        line = std::string(input);
        for (auto iter = line.begin(); iter != line.end(); ++iter) {
            auto found = aeiou.find(*iter);

            if (found != std::string::npos)
                cnt++;
        }

        printf("%zu\n", cnt);
    }

    return 0;
}
