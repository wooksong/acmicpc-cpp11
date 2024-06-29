#include <iostream>
#include <vector>

int to_int (std::string &s);

int
main ()
{
  std::string equation;
  std::string term;
  bool negative = false;
  int sum = 0;

  freopen ("input.txt", "r", stdin);
  std::cin >> equation;

  for (auto iter = equation.begin (); iter != equation.end (); ++iter) {
    if (*iter == '+' || *iter == '-') {
      int val = to_int (term);

      if (!negative) {
        sum += val;
      } else {
        sum -= val;
      }

      if (*iter == '-') {
        negative = true;
      }

      term.clear ();
    } else {
      term.push_back (*iter);
    }
  }

  if (negative)
    sum -= to_int (term);
  else
    sum += to_int (term);

  std::cout << sum << "\n";
  return 0;
}

int
to_int (std::string &s)
{
  bool skip = true;
  int ret = 0;

  for (size_t i = 0; i < s.length (); ++i) {
    if (skip && s[i] == '0') {
      continue;
    } else {
      size_t j;
      int val;

      skip = false;
      val = (static_cast<int> (s[i] - '0'));

      j = (s.length () - 1) - i;
      while (j > 0) {
        val *= 10;
        --j;
      }
      ret += val;
    }
  }

  return ret;
}
