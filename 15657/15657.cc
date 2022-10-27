#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> nums;
std::vector<int> nums_picked;

void get_permutations_rep(int n, int r, int depth);

int main() {
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;

    nums = std::vector<int>(N);
    nums_picked = std::vector<int>(M);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());
    get_permutations_rep(N, M, 0);

    return 0;
}

void get_permutations_rep(int n, int r, int depth) {

    if (r == depth) {
        for (int i = 0; i < r; ++i) {
            std::cout << nums_picked[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (depth != 0 && nums[i] < nums_picked[depth - 1])
            continue;
        nums_picked[depth] = nums[i];
        get_permutations_rep(n, r, depth + 1);
    }
}
