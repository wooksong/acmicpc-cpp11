#include <cmath>
#include <iostream>
#include <vector>

constexpr int MAX_NUM_STORES = 14;

std::vector<std::pair<int, int>> houses;
std::vector<std::pair<int, int>> stores;
std::vector<std::pair<int, int>> stores_picked;
std::vector<int> picked;

int ans = INT32_MAX;
int num_houses = 0;
int num_stores = 0;

int get_min_dist(std::pair<int, int> house, int num_stores_picked) {
    int ret = INT32_MAX;

    for (int i = 0; i < num_stores_picked; ++i) {
        std::pair<int, int> store = stores_picked[i];

        ret = std::min(ret, std::abs(house.first - store.first) +
                                std::abs(house.second - store.second));
    }

    return ret;
}

int get_ck_dist_of_city(int num_houses, int num_stores_picked) {
    int sum = 0;

    for (int i = 0; i < num_houses; ++i) {
        sum += get_min_dist(houses[i], num_stores_picked);
    }

    return sum;
}

void pick(int cur, int m, int depth) {
    if (depth == m) {
        ans = std::min(ans, get_ck_dist_of_city(num_houses, m));
        return;
    }

    for (int i = cur; i < num_stores; ++i) {
        if (!picked[i]) {
            picked[i] = 1;
            stores_picked[depth] = stores[i];
            pick(i, m, depth + 1);
            picked[i] = 0;
        }
    }
}

int main() {
    int N, M;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> M;

    houses = std::vector<std::pair<int, int>>(2 * N + 1);
    stores = std::vector<std::pair<int, int>>(MAX_NUM_STORES);
    picked = std::vector<int>(MAX_NUM_STORES);
    stores_picked = std::vector<std::pair<int, int>>(M);
    num_houses = 0;
    num_stores = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int val;

            std::cin >> val;

            if (val == 1) {
                houses[num_houses++] = {i, j};
            } else if (val == 2) {
                stores[num_stores++] = {i, j};
            }
        }
    }

    pick(0, M, 0);
    std::cout << ans << "\n";
    return 0;
}
