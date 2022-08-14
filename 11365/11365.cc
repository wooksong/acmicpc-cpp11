#include <iostream>
#include <memory.h>

constexpr int MAX_LEN = 501;

int main() {
    const std::string MAGIC_WORD = "END";
    char buf[MAX_LEN];

    // freopen("input.txt", "r", stdin);

    while (std::cin.getline(buf, MAX_LEN, '\n')) {
        std::string code = buf;

        if (code == MAGIC_WORD) {
            break;
        }

        for (auto iter = code.rbegin(); iter != code.rend(); ++iter) {
            printf("%c", *iter);
        }
        printf("\n");
    }

    return 0;
}
