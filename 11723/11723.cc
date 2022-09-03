#include <iostream>

int main() {
    uint32_t S = 0x0;
    uint32_t M;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> M;
    for (uint32_t i = 0; i < M; ++i) {
        std::string cmd;

        std::cin >> cmd;

        if (cmd == "all") {
            for (uint32_t i = 1; i <= 20; ++i) {
                S |= (0x1 << i);
            }
        } else if (cmd == "empty") {
            S = 0x0;
        } else {
            uint32_t n;

            std::cin >> n;
            if (cmd == "add") {
                S |= (0x1U << n);
            } else if (cmd == "remove") {
                uint32_t tmp = S >> n;

                if (tmp & 0x1U) {
                    S ^= (0x1U << n);
                }
            } else if (cmd == "check") {
                std::cout << ((S & (0x1U << n)) ? "1" : "0") << "\n";
            } else if (cmd == "toggle") {
                if (S & (0x1U << n)) {
                    if ((S >> n) & 0x1U) {
                        S ^= (0x1U << n);
                    }
                } else {
                    S |= (0x1U << n);
                }
            }
        }
    }
    return 0;
}
