#include <iostream>

uint32_t get_reverse_num (uint32_t num);

int
main ()
{
  uint32_t A, B;

  std::cin >> A >> B;
  A = get_reverse_num (A);
  B = get_reverse_num (B);

  if (A > B) {
    std::cout << A << "\n";
    return 0;
  }

  std::cout << B << "\n";
  return 0;
}

uint32_t
get_reverse_num (uint32_t num)
{
  uint32_t ret = 0;

  while (num > 0) {
    ret *= 10;
    ret += num % 10;
    num /= 10;
  }

  return ret;
}
