#include <deque>
#include <iostream>
#include <vector>

using net_t = std::vector<std::vector<int>>;

std::vector<bool> infected;
net_t networks;

void bfs (net_t &net);

int
main ()
{
  int num_coms, num_cons;
  int ret;

  // freopen("input.txt", "r", stdin);

  std::cin >> num_coms;
  std::cin >> num_cons;

  networks = net_t (num_coms + 1);
  for (int i = 0; i < num_cons; ++i) {
    int from, to;

    std::cin >> from >> to;

    networks[from].push_back (to);
    networks[to].push_back (from);
  }

  infected = std::vector<bool> (num_coms + 1, false);
  bfs (networks);

  ret = 0;
  for (bool is_infected : infected) {
    if (is_infected)
      ret++;
  }

  std::cout << ret - 1 << "\n";

  return 0;
}

void
bfs (net_t &net)
{
  std::deque<int> queue;

  queue.push_back (1);
  while (!queue.empty ()) {
    std::vector<int> *single_net;
    int v = queue.front ();

    queue.pop_front ();
    infected[v] = true;
    single_net = &net[v];

    for (auto iter = single_net->begin (); iter != single_net->end (); ++iter) {
      if (!infected[*iter])
        queue.push_back (*iter);
    }
  }
}
