#include <cmath>
#include <iostream>
#include <vector>

constexpr int MAX_N = 10001;

int main() {
    std::vector<int> scores(MAX_N, -1);
    int T, N, sum, cnt;
    double ans;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> T;

    while (T--) {
        std::cin >> N;

        sum = 0;
        for (int i = 0; i < N; ++i) {
            std::cin >> scores[i];
            sum += scores[i];
        }

        sum /= N;

        cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (scores[i] > sum) {
                cnt++;
            }
        }

        ans = static_cast<double>(cnt * 1000000 / N) / 10;
        printf("%.3lf%%\n", std::round(ans) / 1000);
    }
    return 0;
}
