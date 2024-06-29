#include <iostream>

constexpr uint32_t MAX_CNTS_NUMS = 9;
int
main ()
{
  uint32_t idx;
  int32_t max = -1;

  // freopen("input.txt", "r", stdin);

  for (uint32_t i = 1; i <= MAX_CNTS_NUMS; ++i) {
    int32_t num;

    std::cin >> num;
    if (num > max) {
      max = num;
      idx = i;
    }
  }

  std::cout << max << "\n";
  std::cout << idx << "\n";

  return 0;
}
