#include <iostream>
#include <vector>

std::vector<uint64_t> remainders;

int
main ()
{
  uint64_t sum;
  uint64_t N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cout.tie (nullptr);
  std::cin.tie (nullptr);

  std::cin >> N;
  remainders.reserve (N);
  for (uint64_t i = 1; i < N; ++i) {
    remainders.push_back (i);
  }

  sum = 0;
  for (uint64_t r : remainders) {
    sum += (N * r + r);
  }

  std::cout << sum << "\n";

  return 0;
}
