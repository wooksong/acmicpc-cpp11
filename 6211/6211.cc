#include <bitset>
#include <iostream>
#include <vector>

constexpr int MAX_B = 22;

std::bitset<MAX_B> visited;
std::vector<int> picked;
std::vector<int> buckets;

int max_cal = INT32_MIN;
int cur_cal = 0;

void pick(int limit, int num_buckets);

int main() {
    int C, B;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> C >> B;

    visited.reset();
    buckets = std::vector<int>(B);

    for (int i = 0; i < B; ++i) {
        std::cin >> buckets[i];
    }

    pick(C, B);
    std::cout << max_cal << "\n";
    return 0;
}

void pick(int limit, int num_buckets) {
    if (cur_cal > limit) {
        return;
    }

    if (cur_cal > max_cal) {
        max_cal = cur_cal;
    }

    for (int i = 0; i < num_buckets; ++i) {
        if (!visited.test(i)) {
            cur_cal += buckets[i];
            visited.set(i);

            pick(limit, num_buckets);
            visited.reset(i);
            cur_cal -= buckets[i];
        }
    }
}
