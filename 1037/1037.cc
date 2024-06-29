#include <iostream>
#include <vector>

int
main ()
{
  uint32_t num_divisors, min, max;

  min = UINT32_MAX;
  max = 1;

  // freopen("input.txt", "r", stdin);
  std::cin >> num_divisors;
  std::vector<uint32_t> divisors = std::vector<uint32_t> (num_divisors);

  for (uint32_t i = 0; i < num_divisors; ++i) {
    std::cin >> divisors[i];

    if (min > divisors[i]) {
      min = divisors[i];
    }

    if (max < divisors[i]) {
      max = divisors[i];
    }
  }

  std::cout << min * max << "\n";
}
