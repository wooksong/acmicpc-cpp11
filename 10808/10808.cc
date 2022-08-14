#include <iostream>
#include <memory.h>

constexpr int NUM_ALPHABET = 26;

int main() {
    std::string S;
    uint32_t alphabetCnt[NUM_ALPHABET];

    // freopen("input.txt", "r", stdin);

    std::cin >> S;
    memset(alphabetCnt, 0, sizeof(alphabetCnt[0]) * NUM_ALPHABET);

    for (auto iter = S.begin(); iter != S.end(); ++iter) {
        int idx = *iter - 'a';

        alphabetCnt[idx]++;
    }

    for (int i = 0; i < NUM_ALPHABET; ++i) {
        printf("%u ", alphabetCnt[i]);
    }
    printf("\n");

    return 0;
}
