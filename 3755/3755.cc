#include <iostream>
#include <set>

using namespace std;
using pii_t = pair<int, int>;

int
main ()
{
  int cmd = -1;
  int client, priority;
  set<pii_t, std::greater<pii_t>> queue;

  ios_base ::sync_with_stdio (false);
  cin.tie (NULL);
  cout.tie (NULL);

  // freopen ("input.txt", "r", stdin);

  while (true && cmd != 0) {
    using namespace std;

    cin >> cmd;

    switch (cmd) {
      case 1:
        {
          cin >> client >> priority;
          queue.insert ({ priority, client });
          break;
        }
      case 2:
        {
          if (queue.empty ()) {
            cout << 0 << "\n";
            continue;
          }
          {
            auto it = queue.begin ();
            cout << it->second << "\n";
            queue.erase (it);
          }
          break;
        }
      case 3:
        {
          if (queue.empty ()) {
            cout << 0 << "\n";
            continue;
          }
          {
            auto it = prev (queue.end ());
            cout << it->second << "\n";
            queue.erase (it);
          }
          break;
        }
      default:
        {
          break;
        }
    }
  }

  return 0;
}
