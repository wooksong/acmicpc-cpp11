#include <iostream>
#include <vector>

constexpr uint32_t MAX_ROOMS = 15;

int
main ()
{
  uint32_t T, k, n;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  std::vector<uint32_t> floors = std::vector<uint32_t> (MAX_ROOMS, 0);
  for (uint32_t i = 0; i < T; ++i) {
    std::cin >> k;
    std::cin >> n;
    for (uint32_t f = 0; f <= k; ++f) {
      for (uint32_t r = 1; r <= n; ++r) {
        if (f == 0) {
          floors[r] = r;
        } else {
          if (r == 1)
            continue;
          floors[r] += floors[r - 1];
        }
      }
    }
    std::cout << floors[n] << "\n";
    floors.clear ();
  }
  return 0;
}
