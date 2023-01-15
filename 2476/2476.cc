#include <iostream>
#include <unordered_map>

constexpr size_t NUM_TRIES = 3;

int main() {
    std::unordered_map<int, int> bucket;
    int max_rewards = INT32_MIN;
    int N;

    // freopen("input.txt", "r", stdin);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int reward = 0;
        size_t num_eyes;

        bucket.clear();

        for (size_t j = 0; j < NUM_TRIES; ++j) {
            int eye;

            std::cin >> eye;

            if (bucket.find(eye) == bucket.end()) {
                bucket[eye] = 1;
            } else {
                ++bucket[eye];
            }
        }

        num_eyes = bucket.size();
        if (num_eyes == 1) {
            auto eye = bucket.begin();

            reward = 10000 + eye->first * 1000;
        } else if (num_eyes == (NUM_TRIES - 1)) {
            for (auto eye = bucket.begin(); eye != bucket.end(); ++eye) {
                if (eye->second == 2) {
                    reward = 1000 + eye->first * 100;
                    break;
                }
            }
        } else {
            int max_eye = 0;

            for (auto eye = bucket.begin(); eye != bucket.end(); ++eye) {
                if (eye->first > max_eye) {
                    max_eye = eye->first;
                }
            }

            reward = max_eye * 100;
        }

        if (reward > max_rewards) {
            max_rewards = reward;
        }
    }

    std::cout << max_rewards << "\n";

    return 0;
}
