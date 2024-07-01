#include <iostream>
#include <unordered_set>

struct Time {
  int hour;
  int min;

  Time (int hour = -1, int min = -1) : hour{ hour }, min{ min }
  {
  }

  bool operator== (const Time &rhs)
  {
    return hour == rhs.hour && min == rhs.min;
  }

  bool operator<(const Time &rhs)
  {
    if (hour == rhs.hour)
      return min < rhs.min;
    return hour < rhs.hour;
  }

  bool operator() (const Time &lhs, const Time &rhs)
  {
    if (lhs.hour == rhs.hour)
      return lhs.min < rhs.min;
    return lhs.hour < rhs.hour;
  }

  void print ()
  {
    std::cout << hour << ":" << min << "\n";
  }
};

int
main ()
{
  const size_t MAX_BUF_SIZE = 21;
  const size_t MAX_NAMES = 100001;

  int h, m, ans;
  Time S, E, Q;
  std::unordered_set<std::string> names;

  char buf[MAX_BUF_SIZE];

  // freopen ("input.txt", "r", stdin);
  names.reserve (MAX_NAMES);

  scanf ("%d:%d", &h, &m);
  S = Time (h, m);

  scanf ("%d:%d", &h, &m);
  E = Time (h, m);

  scanf ("%d:%d", &h, &m);
  Q = Time (h, m);

  ans = 0;
  while (scanf ("%d:%d %s", &h, &m, buf) != EOF) {
    Time t (h, m);
    std::string n (buf);

    if (t < S || t == S) {
      names.insert (n);
    } else if ((E == t || E < t) && (t == Q || t < Q)) {
      if (names.find (n) != names.end ()) {
        names.erase (n);
        ++ans;
      }
    }
  }

  std::cout << ans << "\n";

  return 0;
}
