#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> buckets;
  int N, M;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N >> M;
  buckets = std::vector<int> (N + 1, 0);

  for (int m = 0; m < M; ++m) {
    int from, to, num;

    std::cin >> from >> to >> num;

    for (int i = from; i <= to; ++i) {
      buckets[i] = num;
    }
  }

  for (int n = 1; n <= N; ++n) {
    std::cout << buckets[n] << " ";
  }
  std::cout << "\n";

  return 0;
}
