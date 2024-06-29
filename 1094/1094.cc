#include <iostream>

int
main ()
{
  uint32_t X, cnt;

  std::cin >> X;
  cnt = 0;
  while (X != 0) {
    if (X & 0x1u) {
      cnt++;
    }

    X >>= 1;
  }

  std::cout << cnt << "\n";
  return 0;
}
