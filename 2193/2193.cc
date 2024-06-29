#include <iostream>

constexpr int MAX_N = 91;

uint64_t dp[MAX_N];

int
main ()
{
  int N;

  std::cin >> N;

  dp[1] = 1U;
  dp[2] = 1U;
  dp[3] = 2U;
  for (int i = 4; i <= N; ++i) {
    dp[i] = dp[i - 2] + dp[i - 1];
  }
  std::cout << dp[N] << "\n";

  return 0;
}
