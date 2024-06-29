#include <iostream>
#include <vector>

constexpr size_t MAX_NUM = 10;

int
main ()
{
  uint32_t A, B, C, res;

  // freopen("input.txt", "r", stdin);
  std::vector<uint32_t> zero_to_nine = std::vector<uint32_t> (MAX_NUM, 0);
  std::cin >> A;
  std::cin >> B;
  std::cin >> C;

  res = A * B * C;
  while (res != 0) {
    zero_to_nine[res % 10]++;
    res /= 10;
  }

  for (uint32_t cnt : zero_to_nine) {
    std::cout << cnt << "\n";
  }

  return 0;
}
