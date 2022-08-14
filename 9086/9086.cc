#include <iostream>
#include <memory.h>

constexpr int MAX_LEN = 1000;

int main()
{
    uint32_t T;
    char buf[MAX_LEN];

    freopen("input.txt", "r", stdin);

    std::cin >> T;

    for (uint32_t i = 0; i < T; ++i) {
        uint32_t j;
        memset(buf, '\0', MAX_LEN);
        std::cin >> buf;
        for (j = 0; j < MAX_LEN; ++j) {
            if (buf[j] == '\0')
                break;
        }
        printf("%c%c\n", buf[0], buf[j - 1]);
    }

    return 0;
}
