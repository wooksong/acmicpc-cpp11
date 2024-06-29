#include <cmath>
#include <iostream>
#include <vector>

constexpr size_t CNT_NUMS = 10;
constexpr int TARGET_NUM = 100;

int
main ()
{
  std::vector<int> nums (CNT_NUMS);
  int min_diff = INT32_MAX;
  int max_ans = INT32_MIN;
  int diff;

  // freopen("input.txt", "r", stdin);

  std::cin >> nums[0];
  for (size_t i = 1; i < CNT_NUMS; ++i) {
    int n;

    std::cin >> n;
    nums[i] = nums[i - 1] + n;
  }

  for (int n : nums) {
    diff = std::abs (TARGET_NUM - n);

    if (diff < min_diff) {
      min_diff = diff;
      max_ans = n;
    } else if (diff == min_diff) {
      max_ans = std::max (max_ans, n);
    }
  }

  std::cout << max_ans << "\n";
  return 0;
}
