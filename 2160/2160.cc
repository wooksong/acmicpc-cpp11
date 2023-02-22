#include <bitset>
#include <iostream>
#include <vector>

constexpr size_t n_rows = 5;
constexpr size_t n_cols = 7;
constexpr size_t n_pictures = n_rows * n_cols;

using picture_t = std::bitset<n_pictures>;

int main() {
    std::vector<picture_t> pictures;
    size_t min_diff = SIZE_MAX;
    std::pair<int, int> min_diff_pair;
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    pictures = std::vector<picture_t>(N);

    for (int i = 0; i < N; ++i) {
        for (size_t p = 0; p < n_pictures; ++p) {
            char color;

            std::cin >> color;
            if (color == 'X') {
                pictures[i].set(p);
            } else {
                pictures[i].reset(p);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            picture_t diff = (pictures[i] ^ pictures[j]);
            size_t diff_cnt = diff.count();

            if (min_diff > diff_cnt) {
                min_diff = diff_cnt;
                min_diff_pair = {i + 1, j + 1};
            }
        }
    }

    if (min_diff_pair.first > min_diff_pair.second) {
        std::swap(min_diff_pair.first, min_diff_pair.second);
    }
    std::cout << min_diff_pair.first << " " << min_diff_pair.second << "\n";

    return 0;
}
