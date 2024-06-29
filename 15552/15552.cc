#include <iostream>

int
main ()
{
  size_t T;

  std::cin.tie (nullptr);
  std::ios_base::sync_with_stdio (false);

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (size_t i = 0; i < T; ++i) {
    uint32_t A, B;

    std::cin >> A >> B;

    printf ("%u\n", A + B);
  }
  return 0;
}
