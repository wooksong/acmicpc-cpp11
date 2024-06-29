#include <iostream>

constexpr int NUM_CASES = 4;
int
main ()
{
  int N, m;
  int required[NUM_CASES];
  int p_cases = 1;
  int tmp;

  // freopen("input.txt", "r", stdin);

  std::cin >> N >> m;

  required[0] = N;
  required[1] = N / 2;
  required[2] = (N - 1) / 2 + 1;
  required[3] = (N - 1) / 3 + 1;

  if (N == 1) {
    if (N <= m)
      p_cases++;
    goto print_and_return;
  }

  if (N == 2) {
    for (int i = 0; i < NUM_CASES - 1; ++i) {
      if (required[i] <= m) {
        p_cases++;
      }
    }
    goto print_and_return;
  }

  for (int i = 0; i < NUM_CASES; ++i) {
    if (required[i] <= m) {
      p_cases++;
    }
  }

  if ((required[1] + required[3]) <= m)
    p_cases++;

  if ((required[2] + required[3]) <= m)
    p_cases++;

  /*
  tmp = required[1] + required[2] + required[3];
  if (tmp <= m)
      p_cases++;
  */

  tmp = std::min (required[0], required[1] + required[2]) + required[3];
  if (tmp <= m)
    p_cases++;

print_and_return:
  std::cout << p_cases << "\n";

  return 0;
}
