#include <algorithm>
#include <iostream>
#include <vector>

int
main ()
{
  int N;
  std::vector<std::string> v;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  // freopen("input.txt", "r", stdin);
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    std::string str_num;
    std::string s;

    std::cin >> s;
    for (auto iter = s.begin (); iter != s.end (); ++iter) {
      if ((*iter >= '0') && (*iter <= '9')) {
        str_num += *iter;
      } else {
        if (str_num.size ()) {
          size_t pos = str_num.find_first_not_of ('0');

          if (pos == std::string::npos) {
            v.push_back ("0");
          } else {
            v.push_back (str_num.substr (str_num.find_first_not_of ('0')));
          }
        }
        str_num.clear ();
      }
    }

    if (str_num.size ()) {
      size_t pos = str_num.find_first_not_of ('0');

      if (pos == std::string::npos) {
        v.push_back ("0");
      } else {
        v.push_back (str_num.substr (str_num.find_first_not_of ('0')));
      }
    }
  }

  struct {
    bool operator() (std::string &lhs, std::string &rhs)
    {
      if (lhs.size () < rhs.size ()) {
        return true;
      }

      if (lhs.size () == rhs.size ()) {
        return lhs < rhs;
      }

      return false;
    }
  } cmp;
  std::sort (v.begin (), v.end (), cmp);
  for (size_t i = 0; i < v.size (); ++i) {
    std::cout << v[i] << "\n";
  }
  return 0;
}
