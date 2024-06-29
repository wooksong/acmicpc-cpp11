#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
ll min_time = __LONG_LONG_MAX__;

void parametric_search (std::vector<int> &v, ll lower, ll upper, ll target);

int
main ()
{
  int N, M;
  std::vector<int> required_times;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M;

  required_times = std::vector<int> (N);

  for (int i = 0; i < N; ++i) {
    std::cin >> required_times[i];
  }

  std::sort (required_times.begin (), required_times.end ());
  parametric_search (required_times, 1, 1000000000001LL, M);

  std::cout << min_time << "\n";

  return 0;
}

void
parametric_search (std::vector<int> &v, ll lower, ll upper, ll target)
{
  ll median;
  ll balloons;

  if (lower > upper)
    return;

  balloons = 0;
  median = (lower + upper) / 2;

  for (int i = 0; i < static_cast<int> (v.size ()); ++i) {
    balloons += (median / v[i]);
  }

  if (balloons >= target) {
    min_time = std::min (min_time, median);
    parametric_search (v, lower, median - 1, target);
  } else {
    parametric_search (v, median + 1, upper, target);
  }
}
