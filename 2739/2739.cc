#include <iostream>

using namespace std;

int
main ()
{
  uint32_t N;

  cin >> N;

  for (uint32_t i = 1; i < 10; ++i) {
    printf ("%u * %u = %u\n", N, i, N * i);
  }

  return 0;
}
