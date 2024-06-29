#include <iostream>
#include <vector>

int
main ()
{
  std::vector<int> buckets;
  int N, M;

  freopen ("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N >> M;
  buckets.reserve (N);

  for (int i = 1; i <= N; ++i) {
    buckets.push_back (i);
  }

  for (int i = 0; i < M; ++i) {
    int l, r;

    std::cin >> l >> r;

    std::swap (buckets[l - 1], buckets[r - 1]);
  }

  for (int i : buckets) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
