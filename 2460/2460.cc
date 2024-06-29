#include <iostream>

constexpr uint32_t NUM_STATIONS = 10;

int
main ()
{
  uint32_t out, in, sum, max;

  // freopen("input.txt", "r", stdin);

  sum = 0;
  max = 0;
  for (uint32_t i = 0; i < NUM_STATIONS; ++i) {
    std::cin >> out >> in;
    sum -= out;
    sum += in;
    if (sum > max)
      max = sum;
  }

  printf ("%u\n", max);

  return 0;
}
