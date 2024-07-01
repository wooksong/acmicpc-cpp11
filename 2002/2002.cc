#include <iostream>
#include <unordered_map>
#include <vector>

int
main ()
{
  const size_t LEN_PLATE = 9;
  char buf[LEN_PLATE];
  size_t num_cars;

  std::unordered_map<std::string, size_t> cars;
  std::vector<size_t> order;

  // freopen ("input.txt", "r", stdin);
  std::cin >> num_cars;

  order.reserve (num_cars);
  for (size_t i = 0; i < num_cars; ++i) {
    scanf ("%s", buf);
    {
      std::string car (buf);

      cars[car] = i;
    }
  }

  for (size_t i = 0; i < num_cars; ++i) {
    scanf ("%s", buf);
    {
      std::string car (buf);

      order.emplace_back (cars[car]);
    }
  }
  size_t cnt = 0;
  for (size_t i = 0; i < num_cars; ++i) {
    size_t cur = order[i];
    for (size_t j = i; j < num_cars; ++j) {
      if (cur > order[j]) {
        cnt++;
        break;
      }
    }
  }

  std::cout << cnt << "\n";

  return 0;
}
