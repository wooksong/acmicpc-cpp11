#include <algorithm>
#include <iostream>
#include <vector>

namespace problem {
int N;
int M;
int ans = INT32_MAX;
} // namespace problem

void binary_search(std::vector<int> &jewels, int s, int e);

int main() {
    std::vector<int> vec_jewels;

    // freopen("input.txt", "r", stdin);
    std::cin >> problem::N >> problem::M;
    for (int i = 0; i < problem::M; ++i) {
        int num_jewels;

        std::cin >> num_jewels;
        vec_jewels.push_back(num_jewels);
    }
    std::sort(vec_jewels.begin(), vec_jewels.end());
    binary_search(vec_jewels, 1, vec_jewels.back());

    std::cout << problem::ans << "\n";
}

void binary_search(std::vector<int> &jewels, int val_s, int val_e) {
    int val_m;
    int sum;

    if (val_s > val_e)
        return;

    val_m = (val_s + val_e) / 2;
    sum = 0;
    for (auto iter = jewels.begin(); iter != jewels.end(); ++iter) {
        if (*iter % val_m == 0) {
            sum += (*iter / val_m);
        } else {
            sum += (*iter / val_m) + 1;
        }
    }

    if (sum > problem::N) {
        binary_search(jewels, val_m + 1, val_e);
    } else {
        problem::ans = std::min(val_m, problem::ans);
        binary_search(jewels, val_s, val_m - 1);
    }
}
