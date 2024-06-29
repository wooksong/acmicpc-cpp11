#include <iostream>
#include <memory.h>

constexpr int NUMNUM = 101;

int
main ()
{
  uint32_t N, cnt;
  int v;
  int nums[NUMNUM];

  // freopen("input.txt", "r", stdin);

  memset (nums, -101, sizeof (nums[0]) * NUMNUM);

  std::cin >> N;
  for (uint32_t i = 0; i < N; ++i) {
    nums[i] = -NUMNUM;
  }

  for (uint32_t i = 0; i < N; ++i) {
    std::cin >> nums[i];
  }

  std::cin >> v;

  cnt = 0;
  for (uint32_t i = 0; i < N; ++i) {
    if (nums[i] == -NUMNUM)
      break;
    if (nums[i] == v) {
      cnt++;
    }
  }

  printf ("%u\n", cnt);

  return 0;
}
