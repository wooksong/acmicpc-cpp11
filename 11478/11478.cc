#include <iostream>
#include <set>

int
main ()
{
  std::string line;
  std::set<std::string> strset;

  // freopen ("input.txt", "r", stdin);

  std::cin >> line;
  {
    size_t len = line.length ();

    for (size_t i = 0; i < len; ++i) {
      for (size_t j = 1; j <= len; ++j) {
        std::string sub = line.substr (i, j);

        strset.insert (sub);
      }
    }
  }

  std::cout << strset.size () << "\n";

  return 0;
}
