#include <deque>
#include <iostream>

int
main ()
{
  std::deque<std::pair<std::string, bool>> queue;
  std::string S, T, rev_S;
  bool found = false;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> S;
  std::cin >> T;
  rev_S = std::string (S.rbegin (), S.rend ());

  queue.push_back (std::make_pair (T, false));

  while (!queue.empty ()) {
    std::pair<std::string, bool> from = queue.front ();
    std::string to;
    queue.pop_front ();

    if ((!from.second && from.first == rev_S) || (from.second && from.first == S)) {
      found = true;
      break;
    }

    if (from.second) {
      if (from.first.front () == 'A') {
        to = std::string (from.first, 1, from.first.length ());
        queue.push_back (std::make_pair (to, from.second));
      } else if (from.first.front () == 'B') {
        to = std::string (from.first, 1, from.first.length ());
        queue.push_back (std::make_pair (to, !from.second));
      }
    } else {
      if (from.first.back () == 'A') {
        to = std::string (from.first, 0, from.first.length () - 1);
        queue.push_back (std::make_pair (to, from.second));
      } else if (from.first.back () == 'B') {
        to = std::string (from.first, 0, from.first.length () - 1);
        queue.push_back (std::make_pair (to, !from.second));
      }
    }
  }

  std::cout << found << "\n";

  return 0;
}
