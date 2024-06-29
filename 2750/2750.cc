#include <iostream>
#include <vector>

constexpr int MAX_NUM = 1001;

int tmp[MAX_NUM];
std::vector<int> arr;

void merge (int idx_s, int idx_m, int idx_e);
void sort (int idx_s, int idx_e);

int
main ()
{
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N;

  arr = std::vector<int> (N);
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }

  sort (0, N);

  for (int i : arr) {
    std::cout << i << "\n";
  }

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
    if (arr[i] < arr[j]) {
      tmp[pos++] = arr[i++];
    } else {
      tmp[pos++] = arr[j++];
    }
  }

  while (i < idx_m) {
    tmp[pos++] = arr[i++];
  }

  while (j < idx_e) {
    tmp[pos++] = arr[j++];
  }

  for (i = idx_s; i < idx_e; ++i) {
    arr[i] = tmp[i];
  }
}

void
sort (int idx_s, int idx_e)
{
  int idx_m;

  if ((idx_e - idx_s) < 2) {
    return;
  }

  idx_m = (idx_e - idx_s) / 2 + idx_s;

  sort (idx_s, idx_m);
  sort (idx_m, idx_e);
  merge (idx_s, idx_m, idx_e);
}
