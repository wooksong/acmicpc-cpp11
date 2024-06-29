#include <iostream>

int
main ()
{
  int N, nums_eff_p;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  nums_eff_p = 0;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    int plugs;

    std::cin >> plugs;
    nums_eff_p += plugs;
  }

  nums_eff_p -= (N - 1);

  std::cout << nums_eff_p << "\n";

  return 0;
}
