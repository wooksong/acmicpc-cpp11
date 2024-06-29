#include <iostream>

int
main ()
{
  uint32_t A, B;

  // freopen("input.txt", "r", stdin);
  while (true) {
    std::cin >> A >> B;

    if (A == 0 && B == 0) {
      break;
    }

    std::cout << A + B << "\n";
  }
  return 0;
}
