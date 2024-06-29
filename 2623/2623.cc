#include <iostream>
#include <queue>
#include <vector>

std::vector<int> in_degrees;
std::vector<std::vector<int>> dag;

void topology_sort (size_t num_entries, std::vector<int> &ans);

int
main ()
{
  std::vector<int> ans;
  size_t N;
  int M;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N >> M;

  in_degrees = std::vector<int> (N + 1, 0);
  dag = std::vector<std::vector<int>> (N + 1);
  for (int i = 0; i < M; ++i) {
    int num_singers;
    int former = -1;

    std::cin >> num_singers;
    for (int j = 0; j < num_singers; ++j) {
      if (former == -1) {
        std::cin >> former;
      } else {
        int latter;

        std::cin >> latter;
        dag[former].push_back (latter);
        in_degrees[latter]++;
        former = latter;
      }
    }
  }

  topology_sort (N, ans);
  if (ans.size () != N) {
    std::cout << "0\n";
  } else {
    for (auto n = ans.begin (); n != ans.end (); ++n) {
      std::cout << *n << "\n";
    }
  }

  return 0;
}

void
topology_sort (size_t num_entries, std::vector<int> &ans)
{
  std::queue<int> q;

  for (size_t i = 1; i <= num_entries; ++i) {
    if (in_degrees[i] == 0) {
      q.push (i);
    }
  }

  while (!q.empty ()) {
    int node = q.front ();

    q.pop ();
    ans.push_back (node);

    for (auto l = dag[node].begin (); l != dag[node].end (); ++l) {
      int cur_node = *l;

      --in_degrees[cur_node];
      if (in_degrees[cur_node] == 0) {
        q.push (cur_node);
      }
    }
  }
}
