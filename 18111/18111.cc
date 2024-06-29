#include <algorithm>
#include <iostream>
#include <vector>

constexpr int MAX_N = 501;
constexpr int MAX_M = 501;
constexpr int MAX_MAP = MAX_N * MAX_M;

int
main ()
{
  int max_z = INT32_MIN;
  int min_z = INT32_MAX;
  int N, M, B, pos, size, spare, height;
  int elapsed_min = INT32_MAX;
  int map[MAX_MAP];

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M >> B;
  pos = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int tmp;

      std::cin >> tmp;
      map[pos++] = tmp;
      if (tmp > max_z) {
        max_z = tmp;
      }
      if (tmp < min_z) {
        min_z = tmp;
      }
    }
  }
  size = pos;
  height = -1;
  for (int i = min_z; i <= max_z; ++i) {
    int elapsed = 0;
    int diff;

    spare = B;
    for (int j = 0; j < size; ++j) {
      if (map[j] == i)
        continue;
      if (map[j] > i) {
        diff = map[j] - i;
        spare += diff;
        elapsed += (diff * 2);
      } else {
        diff = i - map[j];
        spare -= diff;
        elapsed += diff;
      }
    }

    if ((spare >= 0) && (elapsed <= elapsed_min)) {
      elapsed_min = elapsed;
      height = i;
    }
  }

  std::cout << elapsed_min << " " << height << "\n";
  return 0;
}
