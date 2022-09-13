#include <algorithm>
#include <iostream>
#include <vector>

uint64_t binary_search(std::vector<uint64_t> v, uint64_t min, uint64_t max,
                       uint64_t num);

int main() {
    uint64_t K, N, ans;
    std::vector<uint64_t> v;

    // freopen("input.txt", "r", stdin);
    std::cin >> K >> N;

    v = std::vector<uint64_t>(K);
    for (uint64_t i = 0; i < K; ++i) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());
    ans = binary_search(v, 1, v.back() + 1, N);
    std::cout << ans << "\n";

    return 0;
}

uint64_t binary_search(std::vector<uint64_t> v, uint64_t min, uint64_t max,
                       uint64_t num) {
    uint64_t num_cables = 0;
    uint64_t mid = (max - min) / 2 + min;

    if (mid == min)
        return mid;

    for (size_t i = 0; i < v.size(); ++i) {
        num_cables += (v[i] / mid);
    }

    if (num_cables >= num) {
        return binary_search(v, mid, max, num);
    } else {
        return binary_search(v, min, mid, num);
    }
}
