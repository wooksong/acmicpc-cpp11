#include <iostream>
#include <vector>

constexpr int MAX_N = 1001;

uint64_t computers[MAX_N][MAX_N];

int main() {
    uint64_t ans = 0;
    uint64_t max = 0;
    uint64_t min = UINT64_MAX;
    double num_comps;
    uint64_t N;
    uint64_t l, r;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    num_comps = 0;
    for (uint64_t i = 0; i < N; ++i) {
        for (uint64_t j = 0; j < N; ++j) {
            uint64_t num;

            std::cin >> num;
            max = std::max(num, max);
            computers[i][j] = num;
            num_comps += num;
        }
    }

    l = min;
    r = max + 1;

    num_comps = num_comps * 100 / 2;
    while ((l + 1) < r) {
        uint64_t m = (l + r) / 2;
        uint64_t sum = 0;

        for (uint64_t i = 0; i < N; ++i) {
            for (uint64_t j = 0; j < N; ++j) {
                sum += (computers[i][j] < m ? computers[i][j] : m);
            }
        }
        sum *= 100;
        if (sum >= num_comps) {
            ans = m;
            r = m;
        } else {
            l = m;
        }
    }
    std::cout << ans << "\n";

    return 0;
}
