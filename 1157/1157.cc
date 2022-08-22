#include <iostream>
#include <vector>

constexpr size_t NUMS_ALPHABET = 26;
int main() {
    std::string word;
    int32_t max;
    uint32_t cnts_max;
    size_t idx_max;

    // freopen("input.txt", "r", stdin);
    std::cin >> word;
    std::vector<int32_t> charcnts = std::vector<int32_t>(NUMS_ALPHABET, 0);
    for (auto iter = word.begin(); iter != word.end(); ++iter) {
        size_t idx;

        if (*iter >= 'A' && *iter <= 'Z') {
            idx = *iter - 'A';
        } else if (*iter >= 'a' && *iter <= 'z') {
            idx = *iter - 'a';
        }

        charcnts[idx]++;
    }

    max = -1;
    for (int32_t cnt : charcnts) {
        if (max < cnt) {
            max = cnt;
        }
    }

    cnts_max = 0;
    for (size_t i = 0; i < NUMS_ALPHABET; ++i) {
        if (max == charcnts[i]) {
            cnts_max++;
            idx_max = i;
        }
    }

    if (cnts_max > 1) {
        std::cout << "?\n";
    } else {
        printf("%c\n", 'A' + static_cast<char>(idx_max));
    }

    return 0;
}
