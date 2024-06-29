#include <iostream>

constexpr int MAX_N = 1001;
constexpr int DIVISOR = 10007;

int
main ()
{
  int dp[MAX_N];
  int N;

  std::cin >> N;

  dp[1] = 1;
  dp[2] = 3;

  for (int i = 3; i <= N; ++i) {
    dp[i] = (dp[i - 1] % DIVISOR) + ((2 * dp[i - 2]) % DIVISOR);
    dp[i] %= DIVISOR;
  }

  std::cout << dp[N] << "\n";

  return 0;
}
