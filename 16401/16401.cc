#include <algorithm>
#include <iostream>
#include <vector>

void binary_search(std::vector<int> v, int target, int lower, int upper);

int ans = INT32_MIN;

int main() {
    int N, M, max;
    std::vector<int> lens_cookies;

    // freopen("input.txt", "r", stdin);

    std::cin >> M >> N;

    max = INT32_MIN;
    lens_cookies = std::vector<int>(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> lens_cookies[i];
        if (max < lens_cookies[i])
            max = lens_cookies[i];
    }
    binary_search(lens_cookies, M, 1, max);
    if (ans == INT32_MIN) {
        std::cout << "0\n";
    } else {
        std::cout << ans << "\n";
    }
    return 0;
}

void binary_search(std::vector<int> v, int target, int lower, int upper) {
    int mid;
    int sum;

    if (lower > upper)
        return;

    mid = (upper + lower) / 2;
    sum = 0;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        if (*iter < mid)
            continue;
        sum += (*iter / mid);
    }

    if (sum >= target) {
        ans = std::max(ans, mid);
        binary_search(v, target, mid + 1, upper);
    } else {
        binary_search(v, target, lower, mid - 1);
    }
}
