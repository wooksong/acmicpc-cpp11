#include <iostream>

int
main ()
{
  uint32_t T;
  int A, B;

  // freopen("input.txt", "r", stdin);

  std::cin >> T;

  for (uint32_t i = 0; i < T; ++i) {
    std::cin >> A >> B;
    printf ("%d\n", A + B);
  }

  return 0;
}
