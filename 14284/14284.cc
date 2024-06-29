#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX_NUM_NODES = 5001;
constexpr int INF = INT32_MAX;

struct EdgeInfo {
  int to;
  int weight;

  EdgeInfo (int t, int w)
  {
    to = t;
    weight = w;
  }

  bool operator<(const EdgeInfo rhs) const
  {
    if (weight > rhs.weight)
      return true;
    if (weight == rhs.weight)
      return (to < rhs.to);
    return false;
  }
};

std::vector<std::vector<EdgeInfo>> graph (MAX_NUM_NODES);
std::vector<int> costs;

void dijkstra (int start);

int
main ()
{
  int n, m, s, t;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int from, to, weight;

    std::cin >> from >> to >> weight;
    graph[from].push_back (EdgeInfo (to, weight));
    graph[to].push_back (EdgeInfo (from, weight));
  }
  std::cin >> s >> t;
  costs = std::vector<int> (n + 1, INF);
  costs[s] = 0;
  dijkstra (s);

  std::cout << costs[t] << "\n";

  return 0;
}

void
dijkstra (int start)
{
  std::priority_queue<EdgeInfo> pq;

  pq.push (EdgeInfo (start, 0));

  while (!pq.empty ()) {
    int cur = pq.top ().to;

    pq.pop ();

    for (auto iter = graph[cur].begin (); iter != graph[cur].end (); ++iter) {
      int next = (*iter).to;
      int next_w = (*iter).weight;

      if (costs[next] > costs[cur] + next_w) {
        costs[next] = costs[cur] + next_w;
        pq.push (EdgeInfo (next, costs[cur] + next_w));
      }
    }
  }
}
