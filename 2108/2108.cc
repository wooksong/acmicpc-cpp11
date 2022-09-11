#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    std::vector<int64_t> flat_v;
    std::unordered_map<int64_t, uint64_t> dict;
    std::vector<std::pair<int64_t, uint64_t>> v;
    int64_t median, min, max;
    int N;

    struct {
        bool operator()(std::pair<int64_t, uint64_t> lhs,
                        std::pair<int64_t, uint64_t> rhs) {
            if (lhs.second == rhs.second) {
                return lhs.first < rhs.first;
            }
            return lhs.second > rhs.second;
        }
    } freqComp;

    // freopen("input.txt", "r", stdin);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int64_t num;

        std::cin >> num;
        flat_v.push_back(num);
        if (dict.find(num) == dict.end()) {
            dict[num] = 1;
        } else {
            ++dict[num];
        }
    }

    v = std::vector<std::pair<int64_t, uint64_t>>(dict.begin(), dict.end());
    std::sort(flat_v.begin(), flat_v.end());

    // Average
    {
        int64_t sum = 0;
        int64_t avg = 0;
        bool negative = false;

        for (auto iter = flat_v.begin(); iter != flat_v.end(); ++iter) {
            sum += (*iter);
        }

        sum *= 10;
        avg = sum / N;
        if (avg < 0) {
            negative = true;
            avg *= -1;
        }

        if ((avg % 10) >= 5) {
            avg = avg / 10 + 1;
        } else {
            avg = avg / 10;
        }

        if (negative) {
            avg *= -1;
        }

        std::cout << avg << "\n";
    }

    // Median
    {
        min = flat_v.front();
        max = flat_v.back();
        median = flat_v[flat_v.size() / 2];

        std::cout << median << "\n";
    }

    // Mode
    {
        int64_t mode;

        std::stable_sort(v.begin(), v.end(), freqComp);
        mode = v.front().first;
        if ((v.size() > 1) && (v[0].second == v[1].second)) {
            mode = v[1].first;
        }
        std::cout << mode << "\n";
    }

    // Max - Min
    { std::cout << max - min << "\n"; }

    return 0;
}
