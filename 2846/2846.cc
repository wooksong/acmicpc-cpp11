#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> road;
  int N, pi;
  int s, e;
  int len_ascent = 0;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;
  road.reserve (N);

  std::cin >> pi;
  road.push_back (pi);

  s = 0;
  e = 0;
  for (int i = 1; i < N; ++i) {
    std::cin >> pi;

    road.push_back (pi);
    if (road[i] > road[i - 1]) {
      e = i;
    } else {
      s = i;
    }

    if (e > s) {
      len_ascent = std::max (road[e] - road[s], len_ascent);
    }
  }

  std::cout << len_ascent << "\n";

  return 0;
}
