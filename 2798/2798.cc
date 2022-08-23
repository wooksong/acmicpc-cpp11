#include <iostream>
#include <vector>

int main() {
    int num_cards, magic_num, ans;
    std::vector<int> nums;

    // freopen("input.txt", "r", stdin);
    std::cin >> num_cards >> magic_num;
    nums = std::vector<int>(num_cards, 0);

    for (int i = 0; i < num_cards; ++i) {
        std::cin >> nums[i];
    }

    ans = -1;
    for (int i = 0; i < num_cards; ++i) {
        for (int j = 0; j < num_cards; ++j) {
            if (i == j)
                continue;
            for (int k = 0; k < num_cards; ++k) {
                int sum;

                if (i == k || j == k)
                    continue;
                sum = nums[i] + nums[j] + nums[k];
                if (sum > magic_num)
                    continue;
                if (sum > ans)
                    ans = sum;
            }
        }
    }

    std::cout << ans << "\n";
}
