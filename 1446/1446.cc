#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<int, std::vector<std::pair<int, int>>> dict_shortcuts;
    std::vector<int> shortest;
    int N, D;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> D;

    dict_shortcuts =
        std::unordered_map<int, std::vector<std::pair<int, int>>>(D + 1);
    for (int i = 0; i < N; ++i) {
        int from, to, dist;

        std::cin >> from >> to >> dist;

        if (to > D)
            continue;
        if ((to - from) <= dist)
            continue;

        dict_shortcuts[to].push_back({from, dist});
    }

    shortest = std::vector<int>(D + 1, INT32_MAX);
    shortest[0] = 0;
    for (int i = 1; i <= D; ++i) {
        if (dict_shortcuts[i].size() == 0) {
            shortest[i] = shortest[i - 1] + 1;
            continue;
        }
        for (std::pair<int, int> s_with_d : dict_shortcuts[i]) {
            shortest[i] =
                std::min(shortest[i],
                         std::min(shortest[i - 1] + 1,
                                  shortest[s_with_d.first] + s_with_d.second));
        }
    }

    std::cout << shortest[D] << "\n";

    return 0;
}
