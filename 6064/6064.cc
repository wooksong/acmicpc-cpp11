#include <iostream>

int calc_gcd (int M, int N);
int calc_lcm (int M, int N);

int
main ()
{
  int T;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    bool found = false;
    int M, N, x, y;
    int doom_year, upper;

    std::cin >> M >> N >> x >> y;
    if (std::max (M, N) != M) {
      std::swap (M, N);
      std::swap (x, y);
    }
    doom_year = calc_lcm (M, N);
    upper = doom_year / N;

    for (int i = 0; i <= upper; ++i) {
      int year = ((N == y) ? i * N : i * N + y);

      if (year == 0)
        continue;

      if (((M == x) && (year % M == 0)) || ((year % M) == x)) {
        std::cout << year << "\n";
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << -1 << "\n";
    }
  }

  return 0;
}

int
calc_lcm (int big, int small)
{
  int gcd = calc_gcd (big, small);

  return big * small / gcd;
}

int
calc_gcd (int big, int small)
{
  if (small == 0)
    return big;
  return calc_gcd (small, big % small);
}
