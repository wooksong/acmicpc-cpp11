#include <iostream>
#include <set>

int
main ()
{
  using nameset_t = std::set<std::string>;

  nameset_t nameset;
  size_t n;

  freopen ("input.txt", "r", stdin);

  std::cin >> n;

  for (size_t i = 0; i < n; ++i) {
    std::string name;
    std::string record;

    std::cin >> name >> record;

    if (nameset.find (name) != nameset.end ()) {
      nameset.erase (name);
    } else {
      nameset.insert (name);
    }
  }

  for (auto it = nameset.rbegin (); it != nameset.rend (); ++it) {
    std::cout << *it << "\n";
  }
  return 0;
}
