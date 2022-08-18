#include <iostream>
#include <vector>

int main() {
    uint32_t T;
    std::cin >> T;

    for (uint32_t i = 0; i < T; ++i) {
        uint32_t n;
        std::vector<uint32_t> binary;

        std::cin >> n;
        while (n > 0) {
            uint32_t m;
            m = n % 2;
            binary.push_back(m);
            n = n >> 1;
        }

        for (uint32_t j = 0; j < binary.size(); ++j) {
            if (binary[j] == 1U) {
                printf("%u ", j);
            }
        }
        printf("\n");
    }
}
