#include <iostream>

int
main ()
{
  uint32_t A, B;

  // freopen("input.txt", "r", stdin);
  while (scanf ("%u %u\n", &A, &B) != EOF) {
    std::cout << A + B << "\n";
  }

  return 0;
}
