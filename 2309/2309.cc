#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

constexpr int MAX_NUM_DWARFS = 9;
constexpr int NUM_DWARFS = 7;

std::vector<int> h_dwarfs (MAX_NUM_DWARFS);
std::bitset<MAX_NUM_DWARFS> picked_tmp;
std::bitset<MAX_NUM_DWARFS> picked_ans;

void pick (int depth, int &sum);

int
main ()
{
  int sum;

  // freopen("input.txt", "r", stdin);

  for (int i = 0; i < MAX_NUM_DWARFS; ++i) {
    std::cin >> h_dwarfs[i];
  }

  sort (h_dwarfs.begin (), h_dwarfs.end ());
  sum = 0;
  pick (0, sum);
  for (int i = 0; i < MAX_NUM_DWARFS; ++i) {
    if (picked_ans.test (i)) {
      std::cout << h_dwarfs[i] << "\n";
    }
  }

  return 0;
}

void
pick (int depth, int &sum)
{
  if (depth == NUM_DWARFS) {
    if (sum == 100) {
      picked_ans = picked_tmp;
    }
    return;
  }

  for (int i = 0; i < MAX_NUM_DWARFS; ++i) {
    if (!picked_tmp.test (i)) {
      picked_tmp.set (i);
      sum += h_dwarfs[i];
      pick (depth + 1, sum);
      picked_tmp.reset (i);
      sum -= h_dwarfs[i];
    }
  }
}
