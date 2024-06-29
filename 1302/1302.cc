#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

bool
cmp (const std::pair<std::string, int> lhs, const std::pair<std::string, int> rhs)
{
  if (lhs.second == rhs.second) {
    return lhs.first < rhs.first;
  }

  return lhs.second > rhs.second;
}

int
main ()
{
  size_t num_books;
  std::unordered_map<std::string, int> books;

  // freopen ("input.txt", "r", stdin);

  std::cin >> num_books;

  for (size_t i = 0; i < num_books; ++i) {
    std::string title;

    std::cin >> title;

    if (books.find (title) == books.end ()) {
      books[title] = 1;
    } else {
      ++books[title];
    }
  }
  {
    std::vector<std::pair<std::string, int>> v;

    v.reserve (books.size ());

    for (auto it : books) {
      v.emplace_back (it);
    }

    std::sort (v.begin (), v.end (), cmp);

    std::cout << v.front ().first << "\n";
  }


  return 0;
}
