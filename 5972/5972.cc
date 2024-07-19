#include <iostream>
#include <queue>
#include <vector>

const int INF = 0x7FFFFFFF;

using namespace std;
using pii_t = pair<int, int>;

vector<vector<pii_t>> nodes;

int
dijkstra (int start, int n)
{
  priority_queue<pii_t, vector<pii_t>, greater<pii_t>> pq;
  vector<int> dp (n + 1, INF);
  dp[start] = 0;
  pq.push ({ 0, start });

  while (!pq.empty ()) {
    int dist = pq.top ().first;
    int cur = pq.top ().second;

    pq.pop ();

    auto &adj_nodes = nodes[cur];
    for (auto &node : adj_nodes) {
      int cost = dist + node.first;
      int next = node.second;

      if (dp[next] > cost) {
        dp[next] = cost;
        pq.push ({ cost, next });
      }
    }
  }

  return dp[n];
}

int
main ()
{
  int n_nodes;
  int n_edges;

  freopen ("input.txt", "r", stdin);

  cin >> n_nodes >> n_edges;
  nodes = vector<vector<pii_t>> (n_nodes + 1);

  for (int i = 0; i < n_edges; ++i) {
    int from, to;
    int dist;

    std::cin >> from >> to >> dist;

    nodes[from].push_back ({ dist, to });
    nodes[to].push_back ({ dist, from });
  }

  cout << dijkstra (1, n_nodes) << "\n";

  return 0;
}
