#include <iostream>
#include <vector>

std::vector<int> tmp_arr;

void merge (std::vector<int> &v, int idx_s, int idx_m, int idx_e);
void sort (std::vector<int> &v, int idx_s, int idx_e);

int
main ()
{
  int N, k;
  std::vector<int> scores;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> k;
  scores = std::vector<int> (N);
  tmp_arr = std::vector<int> (N);

  for (int i = 0; i < N; ++i) {
    std::cin >> scores[i];
  }

  sort (scores, 0, N);
  std::cout << scores[k - 1] << "\n";

  return 0;
}

void
merge (std::vector<int> &v, int idx_s, int idx_m, int idx_e)
{
  int i, j, pos;

  i = idx_s;
  j = idx_m;
  pos = idx_s;

  while (i < idx_m && j < idx_e) {
    if (v[i] > v[j]) {
      tmp_arr[pos++] = v[i++];
    } else {
      tmp_arr[pos++] = v[j++];
    }
  }

  while (i < idx_m) {
    tmp_arr[pos++] = v[i++];
  }

  while (j < idx_e) {
    tmp_arr[pos++] = v[j++];
  }

  for (i = idx_s; i < idx_e; ++i) {
    v[i] = tmp_arr[i];
  }
}

void
sort (std::vector<int> &v, int idx_s, int idx_e)
{
  int idx_m;

  if ((idx_e - idx_s) < 2)
    return;

  idx_m = idx_s + (idx_e - idx_s) / 2;
  sort (v, idx_s, idx_m);
  sort (v, idx_m, idx_e);
  merge (v, idx_s, idx_m, idx_e);
}
