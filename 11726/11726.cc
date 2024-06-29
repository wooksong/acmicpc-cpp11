#include <iostream>
#include <vector>

constexpr int MAX_N = 1001;
constexpr int DIVISOR = 10007;

std::vector<int> dp (MAX_N, 0);

int
main ()
{
  int n;

  dp[1] = 1;
  dp[2] = 2;

  std::cin >> n;
  for (int i = 3; i <= n; ++i) {
    dp[i] = (dp[i - 2] % DIVISOR) + (dp[i - 1] % DIVISOR);
    dp[i] %= DIVISOR;
  }
  std::cout << dp[n] << "\n";

  return 0;
}
