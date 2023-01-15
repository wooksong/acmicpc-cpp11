#include <iostream>
#include <vector>

const std::vector<int> coins = {25, 10, 5, 1};
std::vector<int> changes;

int main() {
    int T;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> T;

    while (T--) {
        int C, i, remains;

        changes = std::vector<int>(coins.size(), 0);

        std::cin >> C;

        remains = C;
        i = 0;
        for (auto coin = coins.begin(); coin != coins.end(); ++coin) {
            int num_coins = remains / (*coin);

            remains -= (num_coins * (*coin));
            changes[i++] = num_coins;
            if (remains == 0)
                break;
        }

        for (auto n = changes.begin(); n != changes.end(); ++n) {
            std::cout << *n << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
