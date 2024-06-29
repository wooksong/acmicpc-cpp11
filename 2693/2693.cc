#include <iostream>
#include <vector>

constexpr int CNT_NUMS = 10;
int tmp[CNT_NUMS];

void merge (std::vector<int> &v, int s, int m, int e);
void sort (std::vector<int> &v, int s, int e);

int
main ()
{
  int T;
  std::vector<int> v (10, -1);

  // freopen("input.txt", "r", stdin);

  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < CNT_NUMS; ++i) {
      std::cin >> v[i];
    }
    sort (v, 0, CNT_NUMS);
    std::cout << v[2] << "\n";
  }

  return 0;
}

void
merge (std::vector<int> &v, int s, int m, int e)
{
  int i = s, j = m, pos = s;

  while (i < m && j < e) {
    if (v[i] >= v[j]) {
      tmp[pos++] = v[i++];
    } else {
      tmp[pos++] = v[j++];
    }
  }

  while (i < m) {
    tmp[pos++] = v[i++];
  }

  while (j < e) {
    tmp[pos++] = v[j++];
  }

  for (i = s; i < e; ++i) {
    v[i] = tmp[i];
  }
}
void
sort (std::vector<int> &v, int s, int e)
{
  int m = s + (e - s) / 2;

  if ((e - s) == 1)
    return;

  sort (v, s, m);
  sort (v, m, e);
  merge (v, s, m, e);
}
