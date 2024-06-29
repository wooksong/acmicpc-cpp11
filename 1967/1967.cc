#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX_NODES = 100001;

std::vector<int> dists;
std::vector<std::vector<std::pair<int, int>>> tree;
bool is_visited[MAX_NODES];

void dijkstra (int num_nodes, int node_start);

int node_farthest;
int dist_farthest;

int
main ()
{
  int num_nodes;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);

  std::cin >> num_nodes;

  tree = std::vector<std::vector<std::pair<int, int>>> (num_nodes + 1);
  dists = std::vector<int> (num_nodes + 1, INT32_MAX);
  for (int i = 1; i <= num_nodes; ++i) {
    int p, c, w;

    std::cin >> p >> c >> w;
    tree[p].push_back ({ c, -w });
    tree[c].push_back ({ p, -w });
  }

  std::fill_n (is_visited, MAX_NODES, false);
  dijkstra (num_nodes, 1);
  dists = std::vector<int> (num_nodes + 1, INT32_MAX);
  std::fill_n (is_visited, MAX_NODES, false);
  dijkstra (num_nodes, node_farthest);
  std::cout << dist_farthest << "\n";

  return 0;
}

struct Comp {
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

void
dijkstra (int num_nodes, int node_start)
{

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comp> pq;

  pq.push ({ node_start, 0 });
  dists[node_start] = 0;

  while (!pq.empty ()) {
    int node = pq.top ().first;
    int weight = pq.top ().second;

    pq.pop ();

    if (dists[node] < weight)
      continue;

    is_visited[node] = true;

    for (auto iter = tree[node].begin (); iter != tree[node].end (); ++iter) {
      int next = iter->first;
      int next_w = iter->second;

      if (!is_visited[next] && (weight + next_w) < dists[next]) {
        dists[next] = weight + next_w;
        pq.push ({ next, weight + next_w });
      }
    }
  }

  node_farthest = 0;
  dist_farthest = INT32_MIN;
  for (int i = 1; i <= num_nodes; ++i) {
    if (dist_farthest < -dists[i]) {
      node_farthest = i;
      dist_farthest = -dists[i];
    }
  }
}
