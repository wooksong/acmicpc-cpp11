#include <iostream>
#include <vector>

int
get_parent (std::vector<int> &parents, int child)
{
  if (parents[child] == child)
    return child;
  return parents[child] = get_parent (parents, parents[child]);
}

void
make_union (std::vector<int> &parents, int l, int r)
{
  int parent_l = get_parent (parents, l);
  int parent_r = get_parent (parents, r);
  int parent;
  int tmp;

  if (parent_l == parent_r)
    return;

  parent = (parent_l < parent_r ? parent_l : parent_r);

  while (get_parent (parents, l) != parent) {
    tmp = parents[l];
    parents[l] = parent;
    l = tmp;
  }

  while (get_parent (parents, r) != parent) {
    tmp = parents[r];
    parents[r] = parent;
    r = tmp;
  }
}

int
main ()
{
  int N, M;

  std::vector<int> parents;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);
  std::cin >> N >> M;

  parents = std::vector<int> (N + 1);
  for (int i = 0; i <= N; ++i) {
    parents[i] = i;
  }

  for (int i = 0; i < M; ++i) {
    int cmd, l, r;

    std::cin >> cmd >> l >> r;

    if (cmd == 0) {
      make_union (parents, l, r);
      continue;
    } else {
      std::cout << (get_parent (parents, l) == get_parent (parents, r) ? "YES\n" : "NO\n");
    }
  }

  return 0;
}
