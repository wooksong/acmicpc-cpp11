#include <iostream>
#include <set>
#include <unordered_map>

int
main ()
{
  const size_t MAX_REQUESTS = 500001;
  const size_t LEN_STD_ID = 9;
  std::unordered_map<std::string, uint32_t> requests;
  std::set<std::pair<uint32_t, std::string>> list;
  std::string buf;
  uint32_t order = 0;
  size_t n_seats;
  size_t n_students;

  // freopen ("input.txt", "r", stdin);

  requests.reserve (MAX_REQUESTS);
  buf.reserve (LEN_STD_ID);
  std::cin >> n_seats >> n_students;
  for (size_t i = 0; i < n_students; ++i) {
    buf[0] = '\0';

    std::cin >> buf;

    if (requests.find (buf) != requests.end ()) {
      requests.erase (buf);
    }
    requests[buf] = order++;
  }

  for (auto it : requests) {
    list.insert (std::make_pair (it.second, it.first));
  }

  order = 0;
  for (auto it : list) {
    std::cout << it.second << "\n";
    if (++order == n_seats)
      break;
  }


  return 0;
}
