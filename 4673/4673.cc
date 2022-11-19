#include <iostream>

constexpr int MAX_N = 10001;

bool self_nums[MAX_N];

void check_self_num_from(int start);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::fill_n(self_nums, MAX_N, true);
    self_nums[1] = true;

    for (int i = 1; i < MAX_N; ++i) {
        check_self_num_from(i);
    }

    for (int i = 1; i < MAX_N; ++i) {
        if (!self_nums[i])
            continue;
        std::cout << i << "\n";
    }

    return 0;
}

void check_self_num_from(int start) {
    std::string str_num;
    int next = start;

    while (next < MAX_N) {
        str_num = std::to_string(next);
        for (char cdigit : str_num) {
            int digit = static_cast<int>(cdigit - '0');
            next += digit;
        }
        if (next >= MAX_N)
            continue;
        self_nums[next] = false;
    }
}
