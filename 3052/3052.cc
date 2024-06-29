#include <iostream>
#include <vector>

constexpr uint32_t Q = 42;
constexpr uint32_t NUM_INPUTS = 10;
int
main ()
{
  std::vector<uint32_t> remainder_cnts = std::vector<uint32_t> (Q, 0);
  uint32_t i;
  uint32_t ret;

  // freopen("input.txt", "r", stdin);

  for (i = 0; i < NUM_INPUTS; ++i) {
    uint32_t remainder;
    uint32_t in_num;

    std::cin >> in_num;
    remainder = in_num % Q;
    remainder_cnts[remainder]++;
  }

  ret = 0;
  for (i = 0; i < Q; ++i) {
    if (remainder_cnts[i] == 0)
      continue;
    ret++;
  }

  std::cout << ret << "\n";

  return 0;
}
