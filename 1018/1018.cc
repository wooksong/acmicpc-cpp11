#include <iostream>
#include <vector>

#ifndef UINT8_WIDTH
#define UINT8_WIDTH 8
#endif

constexpr uint8_t BLACK_FIRST = 0xAAU;
constexpr uint8_t WHITE_FIRST = 0x55U;
constexpr size_t BOARD_HEIGHT = 8;
constexpr size_t BOARD_WIDTH = 8;
constexpr int NUM_PATTERNS = 2;

enum BOARD_PATTERN {
    BLACK_FIRST_PATTERN,
    WHITE_FIRST_PATTERN,
};

uint8_t board_patterns[NUM_PATTERNS] = {
    BLACK_FIRST,
    WHITE_FIRST,
};

uint32_t count_zero(uint8_t val);

int main() {
    const uint8_t board_patterns[2] = {
        BLACK_FIRST,
        WHITE_FIRST,
    };
    std::vector<uint64_t> board;
    uint32_t N, M, min, cnt_paint;
    uint8_t pattern;

    // freopen("input.txt", "r", stdin);
    std::cin >> N >> M;

    for (uint32_t i = 0; i < N; ++i) {
        uint64_t byte = 0x0;
        uint32_t cnt = 0;
        std::string in;

        std::cin >> in;

        for (auto iter = in.begin(); iter != in.end(); ++iter) {
            if (*iter == 'W') {
                byte |= 0x1U;
            }

            if (++cnt != in.size()) {
                byte <<= 1;
            }
        }
        board.push_back(static_cast<uint64_t>(byte));
    }

    min = UINT32_MAX;
    for (size_t p = 0; p < NUM_PATTERNS; ++p) {
        pattern = board_patterns[p];

        for (size_t i = 0; i <= M - BOARD_WIDTH; ++i) {
            for (size_t j = 0; j <= board.size() - BOARD_HEIGHT; ++j) {
                cnt_paint = 0;

                for (size_t k = 0; k < BOARD_HEIGHT; ++k) {
                    uint8_t cmp = board[j + k] >> i;

                    cmp ^= pattern;
                    cnt_paint += count_zero(cmp);

                    if (pattern == BLACK_FIRST) {
                        pattern = WHITE_FIRST;
                    } else if (pattern == WHITE_FIRST) {
                        pattern = BLACK_FIRST;
                    }
                }
                if (min > cnt_paint) {
                    min = cnt_paint;
                }
            }
        }
    }
    std::cout << min << "\n";
    return 0;
}

uint32_t count_zero(uint8_t val) {
    uint32_t cnt = 0;

    for (uint32_t i = 0; i < UINT8_WIDTH; ++i) {
        if (!((val >> i) & 0x1U)) {
            cnt++;
        }
    }
    return cnt;
}
