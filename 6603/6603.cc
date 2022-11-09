#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

constexpr int MAX_NUMS = 49;
constexpr int MAX_NUMS_PICKED = 6;

std::vector<int> candidates(MAX_NUMS, -1);
std::vector<int> is_picked_candidates(MAX_NUMS, 0);
std::vector<int> picked(MAX_NUMS_PICKED);

std::unordered_map<uint64_t, int> dict;
int num_candidates = -1;

void pick(uint64_t bitmap, int depth);

int main() {
    int cnt = 0;
    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    while (true) {
        std::cin >> num_candidates;
        if (num_candidates == 0) {
            break;
        }

        if (cnt++ > 0) {
            std::cout << "\n";
        }

        for (int i = 0; i < num_candidates; ++i) {
            std::cin >> candidates[i];
            is_picked_candidates[i] = 0;
        }

        std::sort(&candidates[0], &candidates[num_candidates - 1]);
        pick(0, 0);

        dict.clear();
    }

    return 0;
}

void pick(uint64_t bitmap, int depth) {
    if (depth == MAX_NUMS_PICKED) {
        if (dict.find(bitmap) == dict.end()) {
            dict[bitmap] = 1;
            for (int p : picked) {
                std::cout << p << " ";
            }
            std::cout << "\n";
        }

        return;
    }

    for (int i = 0; i < num_candidates; ++i) {
        if (!is_picked_candidates[i]) {
            picked[depth] = candidates[i];
            is_picked_candidates[i] = true;
            bitmap |= (0x1 << i);

            pick(bitmap, depth + 1);

            is_picked_candidates[i] = false;
            bitmap &= ~(0x1 << i);
        }
    }
}
