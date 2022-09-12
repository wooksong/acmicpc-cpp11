#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    int N, C;
    std::unordered_map<uint64_t, std::pair<int, uint32_t>> dict;
    std::vector<std::pair<uint64_t, std::pair<int, uint32_t>>> vec;

    struct {
        bool operator()(std::pair<uint64_t, std::pair<int, uint32_t>> lhs,
                        std::pair<uint64_t, std::pair<int, uint32_t>> rhs) {
            if ((lhs.second.second == rhs.second.second)) {
                return lhs.second.first < rhs.second.first;
            } else if ((lhs.second.second > rhs.second.second)) {
                return true;
            }
            return false;
        };
    } comp;

    // freopen("input.txt", "r", stdin);
    std::cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        uint64_t num;

        std::cin >> num;

        if (dict.find(num) == dict.end()) {
            dict[num].first = i;
            dict[num].second = 1;
        } else {
            dict[num].second = dict[num].second + 1;
        }
    }
    vec = std::vector<std::pair<uint64_t, std::pair<int, uint32_t>>>(
        dict.begin(), dict.end());
    std::stable_sort(vec.begin(), vec.end(), comp);

    for (auto pair_iter : vec) {
        for (uint32_t i = 0; i < pair_iter.second.second; ++i) {
            std::cout << pair_iter.first << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
