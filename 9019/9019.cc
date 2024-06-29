#include <bitset>
#include <deque>
#include <iostream>

constexpr size_t MAX_N = 10000;

std::bitset<MAX_N> is_visited;
std::deque<std::pair<int, std::string>> queue;

int operation_d (int from);
int operation_s (int from);
int operation_l (int from);
int operation_r (int from);

void bfs (int from, int to, std::string &shortest_cmds);
int
main ()
{
  int T;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);
  std::cin >> T;

  while (T--) {
    std::string ans = "";
    int A, B;

    std::cin >> A >> B;
    bfs (A, B, ans);
    std::cout << ans << "\n";
  }

  return 0;
}

int
operation_d (int from)
{
  int ret = from * 2;

  return (ret % 10000);
}

int
operation_s (int from)
{
  if (from == 0)
    return MAX_N - 1;
  return from - 1;
}

int
operation_l (int from)
{
  int first_d = from / 1000;

  return (from * 10 % 10000) + first_d;
}

int
operation_r (int from)
{
  int last_d = from % 10;

  return (from / 10) + last_d * 1000;
}

void
bfs (int from, int to, std::string &shortest_cmds)
{
  const std::string commands = "DSLR";
  queue.clear ();
  queue.push_back ({ from, "" });

  is_visited.reset ();
  is_visited.set (from);

  while (!queue.empty ()) {
    int n = queue.front ().first;
    std::string ccmd = queue.front ().second;

    queue.pop_front ();
    if (n == to) {
      shortest_cmds = ccmd;
      return;
    }

    for (char cmd : commands) {
      std::string new_cmd = ccmd + cmd;
      int val;

      if (cmd == 'D') {
        val = operation_d (n);
      } else if (cmd == 'S') {
        val = operation_s (n);
      } else if (cmd == 'L') {
        val = operation_l (n);
      } else {
        val = operation_r (n);
      }

      if (!is_visited.test (val)) {
        is_visited.set (val);
        queue.push_back ({ val, new_cmd });
      }
    }
  }
}
