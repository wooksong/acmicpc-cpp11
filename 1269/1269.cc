#include <bitset>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::pair<int, int> num_elements;
    std::unordered_map<int, std::bitset<2>> sets;
    std::vector<int> v;
    int diff_fs, diff_sf;

    // freopen("input.txt", "r", stdin);

    std::cin >> num_elements.first >> num_elements.second;

    for (int i = 0; i < num_elements.first; ++i) {
        int n;

        std::cin >> n;
        sets[n].set(0);
    }

    for (int i = 0; i < num_elements.second; ++i) {
        int n;

        std::cin >> n;
        sets[n].set(1);
    }

    diff_fs = 0;
    diff_sf = 0;
    for (auto iter = sets.begin(); iter != sets.end(); ++iter) {
        if (iter->second.test(0) && !iter->second.test(1)) {
            diff_fs++;
        } else if (!iter->second.test(0) && iter->second.test(1)) {
            diff_fs++;
        }
    }

    std::cout << diff_fs - diff_sf << "\n";

    return 0;
}
