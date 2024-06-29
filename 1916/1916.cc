#include <iostream>
#include <queue>
#include <vector>

constexpr int INF = 0x3F3F3F3F;

struct Bus {
  int from;
  int to;
  int cost;

  Bus ()
  {
    to = -1;
    cost = 0;
  }

  Bus (int t, int c)
  {
    to = t;
    cost = c;
  }
};

struct BusCostCompare {
  bool operator() (Bus &lhs, Bus &rhs)
  {
    if (lhs.cost > rhs.cost) {
      return true;
    } else if (lhs.cost == rhs.cost) {
      return lhs.to > rhs.to;
    }
    return false;
  }
};

std::vector<int> costs;
std::priority_queue<Bus, std::vector<Bus>, BusCostCompare> pqueue;
std::vector<std::vector<Bus>> buses;

void search_minimal_cost_path_of (int start);

int
main ()
{
  int num_cities, num_buses;
  int from, to;
  int cost;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> num_cities;
  std::cin >> num_buses;

  buses = std::vector<std::vector<Bus>> (num_cities + 1);
  costs = std::vector<int> (num_cities + 1, INF);

  for (int i = 0; i < num_buses; ++i) {
    std::cin >> from >> to >> cost;

    buses[from].push_back (Bus (to, cost));
  }

  std::cin >> from >> to;

  search_minimal_cost_path_of (from);

  std::cout << costs[to] << "\n";
  return 0;
}

void
search_minimal_cost_path_of (int start)
{
  costs[start] = 0;

  pqueue.push (Bus (start, 0));

  while (!pqueue.empty ()) {
    Bus now = pqueue.top ();
    int to = now.to;
    int cost = now.cost;

    pqueue.pop ();

    if (costs[to] < cost)
      continue;

    for (auto iter = buses[to].begin (); iter != buses[to].end (); ++iter) {
      if (costs[(*iter).to] > (cost + (*iter).cost)) {
        costs[(*iter).to] = cost + (*iter).cost;
        pqueue.push (Bus ((*iter).to, cost + (*iter).cost));
      }
    }
  }
}
