#include <bitset>
#include <iostream>
#include <vector>

constexpr int MAX_N = 21;
std::vector<int> arr;
std::vector<int> picked;
std::bitset<MAX_N> is_picked;

int cnt = 0;
int N, target_sum;

void pick(int next, int depth, int sum);

int main() {
    freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N >> target_sum;

    arr = std::vector<int>(N);
    picked = std::vector<int>(N);
    is_picked.reset();

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    pick(0, 0, 0);

    std::cout << cnt << "\n";

    return 0;
}

void pick(int next, int depth, int sum) {
    if (depth > 0 && sum == target_sum) {
        cnt++;
    }
    if (depth == N) {
        return;
    }

    for (int i = next; i < N; ++i) {
        if (!is_picked.test(i)) {
            is_picked.set(i);
            sum += arr[i];
            picked[depth] = arr[i];
            pick(i + 1, depth + 1, sum);
            sum -= arr[i];
            is_picked.reset(i);
        }
    }
}
