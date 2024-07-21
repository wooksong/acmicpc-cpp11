#include <iostream>
#include <queue>
#include <vector>

using pii_t = std::pair<int, int>;
const int MAX_C = 1000010;
int
main ()
{
  int cmd;
  int client, priority;
  bool visited[MAX_C] = {
    false,
  };

  std::priority_queue<pii_t> high_q;
  std::priority_queue<pii_t> low_q;

  std::ios_base ::sync_with_stdio (false);
  std::cin.tie (NULL);
  std::cout.tie (NULL);
  freopen ("input.txt", "r", stdin);

  while (true) {
    using namespace std;
    std::priority_queue<pii_t> *q;

    cin >> cmd;

    switch (cmd) {
      case 1:
        {
          cin >> client >> priority;
          visited[client] = true;
          high_q.push ({ priority, client });
          low_q.push ({ -priority, client });
          break;
        }
      case 2:
        {
          q = &high_q;
          break;
        }

      case 3:
        {
          q = &low_q;
          break;
          if (low_q.empty ()) {
            cout << 0 << "\n";
            continue;
          }
          {
            int c = low_q.top ().second;

            while (!visited[c]) {
              low_q.pop ();
              if (low_q.empty ())
                break;
            }
            if (low_q.empty ()) {
              cout << 0 << "\n";
              continue;
            } else {
              cout << c << "\n";
              visited[c] = false;
              low_q.pop ();
            }
          }
          break;
        }
      default:
        {
          return 0;
        }
    }

    if (cmd == 2 || cmd == 3) {
      int c = -1;
      while (!q->empty ()) {
        c = q->top ().second;
        q->pop ();
        if (visited[c]) {
          break;
        }
        c = -1;
      }

      if (c == -1) {
        cout << "0\n";
      } else {
        cout << c << "\n";
        visited[c] = false;
      }
    }
  }
  return 0;
}
