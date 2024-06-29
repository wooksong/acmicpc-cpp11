#include <algorithm>
#include <iostream>
#include <vector>

uint64_t binary_search (std::vector<uint64_t> &v, uint64_t min, uint64_t max, uint64_t target);

int
main ()
{
  std::vector<uint64_t> trees;
  uint64_t N, M, ans;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M;
  trees = std::vector<uint64_t> (N);
  for (uint64_t i = 0; i < N; ++i) {
    std::cin >> trees[i];
  }

  std::sort (trees.begin (), trees.end ());
  ans = binary_search (trees, 0, trees.back () + 1, M);

  std::cout << ans << "\n";
  return 0;
}

uint64_t
binary_search (std::vector<uint64_t> &v, uint64_t min, uint64_t max, uint64_t target)
{
  uint64_t mid;
  uint64_t sum;

  sum = 0;
  if ((max - min) <= 1)
    return min;
  mid = (max + min) / 2;

  for (auto iter = v.begin (); iter != v.end (); ++iter) {
    if (mid < *iter) {
      sum += (*iter - mid);
    }
  }

  if (sum < target) {
    return binary_search (v, min, mid, target);
  } else if (sum > target) {
    return binary_search (v, mid, max, target);
  } else {
    return mid;
  }
}
