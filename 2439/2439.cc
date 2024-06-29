#include <iostream>

int
main ()
{
  uint32_t N;

  std::cin >> N;

  for (uint32_t i = 0; i < N; ++i) {
    for (uint32_t j = 0; j < (N - i - 1); ++j) {
      printf (" ");
    }
    for (uint32_t j = 0; j < (i + 1); ++j) {
      printf ("*");
    }

    printf ("\n");
  }

  return 0;
}
