#include <iostream>
#include <memory.h>

constexpr int MAX_LEN = 11;

int main() {
    uint32_t N, M;

    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;

    for (uint32_t i = 0; i < N; ++i) {
        char line[MAX_LEN];
        std::string strLine;

        memset(line, '\0', MAX_LEN);
        std::cin >> line;
        strLine = line;
        for (auto iter = strLine.rbegin(); iter != strLine.rend(); ++iter) {
            printf("%c", *iter);
        }
        printf("\n");
    }

    return 0;
}
