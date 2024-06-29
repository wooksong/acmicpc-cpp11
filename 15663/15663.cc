#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> nums;
std::vector<int> picked;
std::vector<int> ans;
std::unordered_map<std::string, uint32_t> dict;
int N, M;

void get_permutations (int depth);

int
main ()
{
  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin.tie (nullptr);
  std::cin >> N >> M;

  nums = std::vector<int> (N);
  picked = std::vector<int> (N, 0);
  ans = std::vector<int> (M);

  for (int i = 0; i < N; ++i) {
    std::cin >> nums[i];
  }

  std::sort (nums.begin (), nums.end ());
  get_permutations (0);

  return 0;
}

void
get_permutations (int depth)
{
  if (depth == M) {
    std::string perm = "";

    for (int n : ans) {
      perm += std::to_string (n);
      perm += ' ';
    }

    if (dict.find (perm) == dict.end ()) {
      dict[perm] = 1;
      std::cout << perm << "\n";
    } else {
      dict[perm]++;
    }

    return;
  }

  for (int i = 0; i < N; ++i) {
    if (!picked[i]) {
      picked[i] = 1;
      ans[depth] = nums[i];
      get_permutations (depth + 1);
      picked[i] = 0;
    }
  }
}
