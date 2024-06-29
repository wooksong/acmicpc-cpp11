#include <iostream>
#include <queue>
#include <vector>

struct Compare {
  bool operator() (std::pair<int, int> &lhs, std::pair<int, int> &rhs)
  {
    if (lhs.second > rhs.second) {
      return true;
    } else if (lhs.second == rhs.second && lhs.first > rhs.first) {
      return true;
    }

    return false;
  }
};

using graph_t = std::vector<std::vector<std::pair<int, int>>>;
using path_t = std::vector<int>;
using paths_t = std::vector<path_t>;

graph_t graph;
paths_t shortest_paths;

void find_shortest_path (int from, path_t &path);

int
main ()
{
  int ans = INT32_MIN;
  int num_nodes, num_roads;
  int dest;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> num_nodes >> num_roads >> dest;

  graph = graph_t (num_nodes + 1);
  shortest_paths = paths_t (num_nodes + 1, path_t (num_nodes + 1, INT32_MAX));
  for (int i = 0; i < num_roads; ++i) {
    int from, to, w;

    std::cin >> from >> to >> w;
    graph[from].push_back ({ to, w });
  }

  for (int i = 1; i <= num_nodes; ++i) {
    path_t *each_path = &shortest_paths[i];
    find_shortest_path (i, *each_path);
  }

  for (int i = 1; i <= num_nodes; ++i) {
    if (i == dest)
      continue;

    ans = std::max (ans, shortest_paths[i][dest] + shortest_paths[dest][i]);
  }

  std::cout << ans << "\n";

  return 0;
}

void
find_shortest_path (int from, path_t &path)
{
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

  pq.push ({ from, 0 });
  path[from] = 0;

  while (!pq.empty ()) {
    int cur_node = pq.top ().first;
    int cur_w = pq.top ().second;

    pq.pop ();

    if (path[cur_node] < cur_w) {
      continue;
    }
    path[cur_node] = cur_w;
    for (auto next = graph[cur_node].begin (); next != graph[cur_node].end (); ++next) {
      int next_node = next->first;
      int next_w = next->second;

      if (path[next_node] > (next_w + path[cur_node])) {
        pq.push ({ next_node, next_w + path[cur_node] });
        path[next_node] = next_w + path[cur_node];
      }
    }
  }
}
