#include <iostream>

int
main ()
{
  int N, n_streaks, sum;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  sum = 0;
  n_streaks = 0;
  for (int i = 0; i < N; ++i) {
    int r;

    std::cin >> r;
    if (!r) {
      n_streaks = 0;
    } else {
      n_streaks++;
    }

    sum += n_streaks;
  }

  std::cout << sum << "\n";

  return 0;
}
