#include <iostream>
#include <set>

int
main ()
{
  std::multiset<std::string> names;

  size_t n_names;

  freopen ("input.txt", "r", stdin);

  std::cin >> n_names;
  for (size_t i = 0; i < n_names; ++i) {
    std::string name;

    std::cin >> name;

    names.insert (name);
  }

  n_names -= 1;
  for (size_t i = 0; i < n_names; ++i) {
    std::string name;

    std::cin >> name;

    names.erase (names.find (name));
  }

  for (auto it : names) {
    std::cout << it << "\n";
  }

  return 0;
}
