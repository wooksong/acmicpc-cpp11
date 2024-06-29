#include <algorithm>
#include <iostream>
#include <vector>

int
main ()
{
  int T;
  int max_difficulty;

  // freopen("input.txt", "r", stdin);

  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::vector<int> wood_logs;
    int N, remains;
    int big, small;

    std::cin >> N;
    wood_logs = std::vector<int> (N);
    for (int n = 0; n < N; ++n) {
      std::cin >> wood_logs[n];
    }

    std::sort (wood_logs.begin (), wood_logs.end ());

    big = wood_logs.back ();
    wood_logs.pop_back ();
    small = wood_logs.back ();
    wood_logs.pop_back ();
    max_difficulty = big - small;

    remains = wood_logs.size ();
    while (remains > 2) {
      max_difficulty = std::max (max_difficulty, big - wood_logs[remains - 1]);
      max_difficulty = std::max (max_difficulty, small - wood_logs[remains - 2]);
      big = wood_logs.back ();
      wood_logs.pop_back ();
      small = wood_logs.back ();
      wood_logs.pop_back ();
      remains = wood_logs.size ();
    }

    if (remains == 2) {
      max_difficulty = std::max (max_difficulty, big - wood_logs[1]);
      max_difficulty = std::max (max_difficulty, small - wood_logs[0]);
      max_difficulty = std::max (max_difficulty, wood_logs[1] - wood_logs[0]);
    } else {
      max_difficulty = std::max (max_difficulty, big - wood_logs[0]);
    }

    std::cout << max_difficulty << "\n";
  }
  return 0;
}
