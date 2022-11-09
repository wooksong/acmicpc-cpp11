#include <cmath>
#include <iostream>
#include <vector>

constexpr int CUR_CH = 100;
constexpr int MAX_NUM_DIGITS = 6;
constexpr int MAX_N = 10;

std::vector<int> buttons;
std::vector<int> picked;

int min_move = INT32_MAX;
int N;

void do_permutation(int num_digits, int depth);

int main() {
    int m;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    std::cin >> m;
    buttons = std::vector<int>(MAX_N, 0);
    picked = std::vector<int>(MAX_NUM_DIGITS, 0);

    for (int i = 0; i < m; ++i) {
        int32_t b;

        std::cin >> b;
        buttons[b] = 1;
    }

    picked = std::vector<int>(MAX_NUM_DIGITS);
    min_move = std::abs(N - CUR_CH);
    for (int i = 1; i <= MAX_NUM_DIGITS; ++i) {
        do_permutation(i, 0);
    }
    std::cout << min_move << "\n";
}

void do_permutation(int num_digits, int depth) {
    if (depth == num_digits) {
        int candidate = 0;
        int mul = 1;
        int move;

        for (int i = 0; i < depth; ++i) {
            candidate += (picked[i] * mul);
            mul *= 10;
        }

        move = std::abs(N - candidate) + depth;
        if (min_move > move) {
            min_move = move;
        }
        return;
    }

    for (int i = 0; i < MAX_N; ++i) {
        if (!buttons[i]) {
            picked[depth] = i;
            do_permutation(num_digits, depth + 1);
        }
    }
}
