#include <iostream>
#include <vector>

constexpr size_t NUM_EDGES = 3;

int
main ()
{
  std::vector<int> edges (NUM_EDGES);
  size_t idx_max = 0;
  int sum;

  // freopen("input.txt", "r", stdin);

  std::cin >> edges[idx_max];
  for (size_t i = 1; i < NUM_EDGES; ++i) {
    std::cin >> edges[i];
    if (edges[i] > edges[idx_max]) {
      idx_max = i;
    }
  }

  std::swap (edges[idx_max], edges[0]);
  if (edges[1] < edges[2]) {
    std::swap (edges[1], edges[2]);
  }

  sum = edges[1] + edges[2];

  if (sum <= edges[0]) {
    std::cout << sum * 2 - 1 << "\n";
  } else {
    std::cout << sum + edges[0] << "\n";
  }

  return 0;
}
