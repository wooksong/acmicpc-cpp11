#include <iostream>
#include <vector>

int main() {
    size_t K;
    int32_t sum = 0;
    std::vector<int32_t> stack;

    // freopen("input.txt", "r", stdin);
    std::cin >> K;
    for (size_t i = 0; i < K; ++i) {
        int32_t n;

        std::cin >> n;
        if (n == 0) {
            int32_t val = stack.back();

            sum -= val;
            stack.pop_back();
        } else {
            sum += n;
            stack.push_back(n);
        }
    }

    std::cout << sum << "\n";

    return 0;
}
