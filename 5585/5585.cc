#include <iostream>

enum CoinType {
    COIN_500 = 0,
    COIN_100,
    COIN_50,
    COIN_10,
    COIN_5,
    COIN_1,
    NUM_COIN_TYPES,
};

static const int CoinVal[NUM_COIN_TYPES] = {500, 100, 50, 10, 5, 1};

int main() {
    int ret, paid, change;

    // freopen("input.txt", "r", stdin);
    std::cin >> paid;
    change = 1000 - paid;

    ret = 0;
    while (change > 0) {
        for (int i = CoinType::COIN_500; i < NUM_COIN_TYPES; ++i) {
            int used = change / CoinVal[i];

            if (used > 0) {
                ret += used;
                change -= (CoinVal[i] * used);
            }
        }
    }

    std::cout << ret << "\n";

    return 0;
}
