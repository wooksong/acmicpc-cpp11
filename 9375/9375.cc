#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::unordered_map<std::string, int> dict;
    int T, n;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // freopen("input.txt", "r", stdin);

    std::cin >> T;

    for (int t = 0; t < T; ++t) {
        int ans = 1;

        std::cin >> n;

        dict.clear();

        for (int i = 0; i < n; ++i) {
            std::string type, clothing;

            std::cin >> clothing >> type;
            if (dict.find(type) == dict.end()) {
                dict[type] = 1;
            } else {
                ++dict[type];
            }
        }
        for (auto iter = dict.begin(); iter != dict.end(); ++iter) {
            ans *= (iter->second + 1);
        }

        std::cout << ans - 1 << "\n";
    }

    return 0;
}
