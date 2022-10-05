#include <algorithm>
#include <iostream>
#include <vector>

constexpr int NUM_LINE_IN_APACK = 6;

struct Price {
    int pack;
    int each;
};

int main() {
    std::vector<Price> prices;
    int N, M;
    int min_pack, min_each;

    struct {
        bool operator()(Price &lhs, Price &rhs) { return lhs.each < rhs.each; }
    } PriceCompEach;

    struct {
        bool operator()(Price &lhs, Price &rhs) { return lhs.pack < rhs.pack; }
    } PriceCompPack;

    // freopen("input.txt", "r", stdin);

    std::cin >> N >> M;

    prices = std::vector<Price>(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> prices[i].pack >> prices[i].each;
    }

    std::sort(prices.begin(), prices.end(), PriceCompPack);
    min_pack = prices.front().pack;
    std::sort(prices.begin(), prices.end(), PriceCompEach);
    min_each = prices.front().each;

    {
        int ans = std::min((N / NUM_LINE_IN_APACK + 1) * min_pack,
                           (N / NUM_LINE_IN_APACK) * min_pack +
                               (N % NUM_LINE_IN_APACK) * min_each);
        ans = std::min(ans, N * min_each);

        std::cout << ans << "\n";
    }

    return 0;
}
