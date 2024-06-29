#include <iostream>

constexpr int MAX_N = 101;
uint64_t dp[MAX_N];

int
main ()
{
  int T;

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;

    std::cin >> n;
    for (int i = 6; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 5];
    }

    std::cout << dp[n] << "\n";
  }
  return 0;
}
