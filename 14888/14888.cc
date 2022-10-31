#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

constexpr int NUM_OPS = 4;

int N;
int min = INT32_MAX;
int max = INT32_MIN;

std::vector<int> nums;
std::vector<int> num_operators;

void pick(int result, int idx);

int main() {
    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;

    nums = std::vector<int>(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }
    num_operators = std::vector<int>(NUM_OPS, 0);

    for (int i = 0; i < NUM_OPS; ++i) {
        std::cin >> num_operators[i];
    }

    pick(nums[0], 1);
    std::cout << max << "\n";
    std::cout << min << "\n";

    return 0;
}

void pick(int result, int idx) {
    if (idx == N) {
        if (result > max) {
            max = result;
        }
        if (result < min) {
            min = result;
        }
        return;
    }

    for (int i = 0; i < NUM_OPS; ++i) {
        if (num_operators[i] > 0) {
            --num_operators[i];
            switch (i) {
            case 0:
                pick(result + nums[idx], idx + 1);
                break;
            case 1:
                pick(result - nums[idx], idx + 1);
                break;
            case 2:
                pick(result * nums[idx], idx + 1);
                break;
            case 3:
                pick(result / nums[idx], idx + 1);
                break;
            }
            ++num_operators[i];
        }
    }
}
