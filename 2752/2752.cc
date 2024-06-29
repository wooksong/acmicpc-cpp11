#include <iostream>

constexpr size_t CNT_NUMS = 3;

int32_t nums[CNT_NUMS];

int
main ()
{
  int32_t min, max, the_other = 0;

  min = INT32_MAX;
  max = -1;

  // freopen("input.txt", "r", stdin);

  std::cin >> nums[0] >> nums[1] >> nums[2];
  for (size_t i = 0; i < CNT_NUMS; ++i) {
    if (nums[i] > max) {
      max = nums[i];
    }

    if (nums[i] < min) {
      min = nums[i];
    }
  }

  for (size_t i = 0; i < CNT_NUMS; ++i) {
    if (nums[i] != max && nums[i] != min) {
      the_other = nums[i];
      break;
    }
  }

  std::cout << min << " " << the_other << " " << max << "\n";

  return 0;
}
