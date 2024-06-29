#include <bitset>
#include <iostream>
#include <vector>

constexpr size_t NUMS_N = 5;

int min_lcm = INT32_MAX;

std::vector<int> nums (NUMS_N);
std::bitset<NUMS_N> picked;

int calc_gcd (int lhs, int rhs);
void pick (std::vector<int> &v, int depth);

int
main ()
{
  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  for (size_t i = 0; i < NUMS_N; ++i) {
    std::cin >> nums[i];
  }

  picked.reset ();
  std::vector<int> vv (3, -1);

  pick (vv, 0);

  std::cout << min_lcm << "\n";

  return 0;
}

int
calc_gcd (int lhs, int rhs)
{
  int next_lhs;

  if (lhs > rhs) {
    std::swap (lhs, rhs);
  }

  next_lhs = rhs % lhs;
  if (rhs % lhs == 0) {
    return lhs;
  } else {
    return calc_gcd (next_lhs, lhs);
  }
}

void
pick (std::vector<int> &v, int depth)
{
  if (depth == 3) {
    int gcd = calc_gcd (v[0], v[1]);
    int lcm = v[0] * v[1] / gcd;

    gcd = calc_gcd (lcm, v[2]);
    lcm = lcm * v[2] / gcd;

    if (min_lcm > lcm) {
      min_lcm = lcm;
    }

    return;
  }

  for (size_t i = 0; i < NUMS_N; ++i) {
    if (picked.test (i))
      continue;
    picked.set (i);
    v[depth] = nums[i];
    pick (v, depth + 1);
    picked.reset (i);
  }
}
