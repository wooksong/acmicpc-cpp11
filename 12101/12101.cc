#include <iostream>
#include <list>

std::list<int> nums;
std::list<int> result;

int n, k;

void pick (int &cur_sum);

int
main ()
{
  int sum;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> n >> k;

  sum = 0;
  pick (sum);
  if (result.empty ()) {
    std::cout << "-1\n";
  } else {
    std::cout << result.front ();
    result.pop_front ();
    while (!result.empty ()) {
      std::cout << "+";
      std::cout << result.front ();
      result.pop_front ();
    }
    std::cout << "\n";
  }
  return 0;
}

void
pick (int &cur_sum)
{
  static int cnt = 0;

  if (cur_sum >= n) {
    if (cur_sum == n) {
      ++cnt;
      if (cnt == k) {
        for (int i : nums) {
          result.push_back (i);
        }
      }
    }
    return;
  }

  for (int i = 1; i <= 3; ++i) {
    cur_sum += i;
    nums.push_back (i);
    pick (cur_sum);
    nums.pop_back ();
    cur_sum -= i;
  }
}
