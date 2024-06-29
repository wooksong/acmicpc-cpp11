#include <iostream>

int
main ()
{
  uint32_t T, A, B;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (uint32_t i = 0; i < T; ++i) {
    std::cin >> A >> B;
    std::cout << "Case #" << i + 1 << ": " << A + B << "\n";
  }
  return 0;
}
