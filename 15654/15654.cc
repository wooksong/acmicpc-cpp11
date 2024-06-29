#include <algorithm>
#include <iostream>
#include <vector>

struct Element {
  int val;
  bool is_visited;

  Element ()
  {
    val = -1;
    is_visited = false;
  };

  bool operator<(Element rhs) const
  {
    return (val < rhs.val);
  }
};

std::vector<Element> elements;
std::vector<int> arr;

void dfs (int n, int r, int depth);

int
main ()
{
  int N, M;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);
  std::cin >> N >> M;

  elements = std::vector<Element> (N);
  arr = std::vector<int> (M);

  for (int i = 0; i < N; ++i) {
    std::cin >> elements[i].val;
    elements[i].is_visited = false;
  }

  std::sort (elements.begin (), elements.end ());
  dfs (N, M, 0);

  return 0;
}

void
dfs (int n, int r, int depth)
{
  if (depth == r) {
    for (int i = 0; i < r; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (!elements[i].is_visited) {
      elements[i].is_visited = true;
      arr[depth] = elements[i].val;
      dfs (n, r, depth + 1);
      elements[i].is_visited = false;
    }
  }
}
