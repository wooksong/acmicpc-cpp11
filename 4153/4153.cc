#include <iostream>

constexpr int NUM_ANGLES = 3;
int
main ()
{
  uint32_t triangle[NUM_ANGLES];

  // freopen("input.txt", "r", stdin);

  while (true) {
    uint32_t heru = 0;
    uint32_t pow_sum = 0;
    bool is_zero = true;

    for (int i = 0; i < NUM_ANGLES; ++i) {
      std::cin >> triangle[i];
      is_zero = is_zero && (triangle[i] == 0);
      triangle[i] *= triangle[i];
      if (triangle[i] > heru) {
        heru = triangle[i];
      }
    }
    if (is_zero)
      break;
    for (int i = 0; i < NUM_ANGLES; ++i) {
      if (triangle[i] == heru)
        continue;
      pow_sum += triangle[i];
    }

    if (pow_sum == heru)
      std::cout << "right\n";
    else
      std::cout << "wrong\n";
  }

  return 0;
}
