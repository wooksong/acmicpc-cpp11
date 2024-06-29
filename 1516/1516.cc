#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> dag;
std::vector<int> in_degrees;
std::vector<int> needed_times;
std::vector<int> dp;

void topology_sort (int nodes);

int
main ()
{
  int num_buildings;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> num_buildings;

  dag = std::vector<std::vector<int>> (num_buildings + 1);
  in_degrees = std::vector<int> (num_buildings + 1, 0);
  needed_times = std::vector<int> (num_buildings + 1, 0);
  dp = std::vector<int> (num_buildings + 1, 0);

  for (int i = 1; i <= num_buildings; ++i) {
    int time_needed;
    int dep;

    std::cin >> time_needed;
    needed_times[i] = time_needed;

    do {
      std::cin >> dep;

      if (dep == -1) {
        break;
      }
      dag[dep].push_back (i);
      ++in_degrees[i];
    } while (dep != -1);
  }

  topology_sort (num_buildings);
  for (int i = 1; i <= num_buildings; ++i) {
    std::cout << dp[i] << "\n";
  }

  return 0;
}

void
topology_sort (int nodes)
{
  std::queue<int> q;

  for (int i = 1; i <= nodes; ++i) {
    if (in_degrees[i] == 0) {
      q.push (i);
      dp[i] = needed_times[i];
    }
  }

  while (!q.empty ()) {
    int cur = q.front ();

    q.pop ();

    for (auto iter = dag[cur].begin (); iter != dag[cur].end (); ++iter) {
      --in_degrees[*iter];
      dp[*iter] = std::max (dp[*iter], dp[cur] + needed_times[*iter]);
      if (in_degrees[*iter] == 0) {
        q.push (*iter);
      }
    }
  }
}
