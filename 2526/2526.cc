#include <cmath>
#include <iostream>
#include <vector>

constexpr uint64_t MAX_P = 98;

int
main ()
{
  std::vector<uint64_t> counts (MAX_P, 0);
  uint64_t N, P;
  uint64_t next;
  int cnt = 0;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N >> P;

  next = N;
  while (true) {
    if (++counts[next] > 2) {
      break;
    }
    next *= N;
    next %= P;
  }
  for (uint64_t i = 0; i < MAX_P; ++i) {
    if (counts[i] > 1) {
      cnt++;
    }
  }

  std::cout << cnt << "\n";

  return 0;
}
