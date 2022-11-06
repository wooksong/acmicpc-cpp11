#include <iostream>

constexpr int MAX_NUM_HOUSES = 1001;
constexpr int NUM_COLORS = 3;

int costs[MAX_NUM_HOUSES][NUM_COLORS];

int main() {
    int N;
    int ans;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    costs[0][0] = 0;
    costs[0][1] = 0;
    costs[0][2] = 0;

    for (int i = 1; i <= N; ++i) {
        int r, g, b;

        std::cin >> r >> g >> b;

        costs[i][0] = std::min(costs[i - 1][1], costs[i - 1][2]) + r;
        costs[i][1] = std::min(costs[i - 1][0], costs[i - 1][2]) + g;
        costs[i][2] = std::min(costs[i - 1][0], costs[i - 1][1]) + b;
    }
    ans = std::min(costs[N][0], costs[N][1]);
    ans = std::min(ans, costs[N][2]);
    std::cout << ans << "\n";

    return 0;
}
