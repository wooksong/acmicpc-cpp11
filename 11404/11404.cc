#include <iostream>
#include <vector>

const int MAX_N_CITIES = 101;
const int INF = 0x7FFFFFFF;
int
main ()
{
  int dp[MAX_N_CITIES][MAX_N_CITIES];
  int n_cities;
  int n_buses;

  // freopen ("input.txt", "r", stdin);
  std::cin >> n_cities;
  std::cin >> n_buses;

  for (int i = 0; i < MAX_N_CITIES; ++i) {
    for (int j = 0; j < MAX_N_CITIES; ++j) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = INF;
    }
  }

  for (int i = 0; i < n_buses; ++i) {
    int from, to, cost;

    std::cin >> from >> to >> cost;
    dp[from][to] = std::min (dp[from][to], cost);
  }

  for (int k = 1; k <= n_cities; ++k) {
    for (int i = 1; i <= n_cities; ++i) {
      for (int j = 1; j <= n_cities; ++j) {
        if (dp[i][k] == INF || dp[k][j] == INF)
          continue;
        dp[i][j] = std::min (dp[i][k] + dp[k][j], dp[i][j]);
      }
    }
  }

  for (int i = 1; i <= n_cities; ++i) {
    for (int j = 1; j <= n_cities; ++j) {
      int cost = dp[i][j];

      if (cost == INF)
        cost = 0;
      std::cout << cost << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
