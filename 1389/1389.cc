#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

std::deque<int> queue;
std::vector<bool> visited;
std::vector<int> steps;
int bfs (std::vector<std::vector<int>> &v, int cur_user);

int
main ()
{
  std::vector<std::vector<int>> users;
  int N, M;
  int min, ans;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M;

  users = std::vector<std::vector<int>> (N + 1);
  steps = std::vector<int> (N + 1);
  visited = std::vector<bool> (N + 1);
  queue = std::deque<int> ();

  for (int i = 0; i < M; ++i) {
    int from, to;

    std::cin >> from >> to;
    users[from].push_back (to);
    users[to].push_back (from);
  }

  for (int i = 0; i < N + 1; ++i) {
    std::sort (users[i].begin (), users[i].end ());
  }

  min = INT32_MAX;
  for (int i = 1; i < N + 1; ++i) {
    int len;

    visited.assign (N + 1, false);
    steps.assign (N + 1, -1);
    len = bfs (users, i);
    if (min > len) {
      ans = i;
      min = len;
    }
  }

  std::cout << ans << "\n";

  return 0;
}

int
bfs (std::vector<std::vector<int>> &v, int cur_user)
{
  std::vector<int> *friends;
  int sum;

  queue.push_back (cur_user);
  steps[cur_user] = 0;
  while (!queue.empty ()) {
    int u = queue.front ();

    if (!visited[u]) {
      visited[u] = true;
    }
    queue.pop_front ();
    friends = &v[u];
    for (auto iter = friends->begin (); iter != friends->end (); ++iter) {
      if (!visited[*iter]) {
        if (steps[*iter] == -1)
          steps[*iter] = steps[u] + 1;
        queue.push_back (*iter);
      }
    }
  }

  sum = 0;
  for (size_t i = 1; i < steps.size (); ++i) {
    sum += steps[i];
  }
  return sum;
}
