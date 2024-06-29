#include <iostream>
#include <vector>

std::vector<int> nums;
std::vector<int> tmp_nums;

void merge (int idx_s, int idx_m, int idx_e);
void sort (int idx_s, int idx_e);
void pick (std::vector<int> &picked, int depth, int n, int m);

int
main ()
{
  std::vector<int> picked;
  int N, M;

  // freopen("input.txt", "r", stdin);

  std::cin >> N >> M;

  nums = std::vector<int> (N);
  tmp_nums = std::vector<int> (N);
  picked = std::vector<int> (M);

  for (int i = 0; i < N; ++i) {
    std::cin >> nums[i];
  }

  sort (0, N);
  pick (picked, 0, N, M);

  return 0;
}

void
merge (int idx_s, int idx_m, int idx_e)
{
  int i, j, pos;

  i = idx_s;
  j = idx_m;
  pos = idx_s;

  while (i < idx_m && j < idx_e) {
    if (nums[i] < nums[j]) {
      tmp_nums[pos++] = nums[i++];
    } else {
      tmp_nums[pos++] = nums[j++];
    }
  }

  while (i < idx_m) {
    tmp_nums[pos++] = nums[i++];
  }

  while (j < idx_e) {
    tmp_nums[pos++] = nums[j++];
  }

  for (i = idx_s; i < idx_e; ++i) {
    nums[i] = tmp_nums[i];
  }
}

void
sort (int idx_s, int idx_e)
{
  int idx_m;

  if (idx_s + 1 >= idx_e)
    return;

  idx_m = idx_s + (idx_e - idx_s) / 2;
  sort (idx_s, idx_m);
  sort (idx_m, idx_e);
  merge (idx_s, idx_m, idx_e);
}

void
pick (std::vector<int> &picked, int depth, int n, int m)
{
  if (depth == m) {
    for (auto iter = picked.begin (); iter != picked.end (); ++iter) {
      std::cout << *iter << " ";
    }
    std::cout << "\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    picked[depth] = nums[i];
    pick (picked, depth + 1, n, m);
  }
}
