#include <iostream>
#include <vector>

constexpr int MAX_M = 31;

int dp[MAX_M][MAX_M];

int get_combinations (int m, int n);

int
main ()
{
  int T;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    int M, N;

    for (int i = 0; i < MAX_M; ++i) {
      for (int j = 0; j < MAX_M; ++j) {
        if ((j == 0) || (j == i))
          dp[i][j] = 1;
        else if (j == 1) {
          dp[i][j] = i;
        } else {
          dp[i][j] = -1;
        }
      }
    }

    std::cin >> N >> M;

    dp[M][0] = 1;
    dp[M][M] = 1;
    dp[M][1] = M;

    std::cout << get_combinations (M, N) << "\n";
  }

  return 0;
}

int
get_combinations (int m, int n)
{
  if (dp[m][n] != -1) {
    return dp[m][n];
  }

  dp[m - 1][n - 1] = get_combinations (m - 1, n - 1);
  dp[m - 1][n] = get_combinations (m - 1, n);
  dp[m][n] = dp[m - 1][n - 1] + dp[m - 1][n];
  return dp[m][n];
}
