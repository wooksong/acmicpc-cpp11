#include <iostream>
#include <unordered_map>

constexpr int NUM_SIDES_GIVEN = 3;
constexpr size_t LIMIT_COORD = 1001;

int
main ()
{
  std::unordered_map<int, int> x_points;
  std::unordered_map<int, int> y_points;
  int ans_x;
  int ans_y;

  freopen ("input.txt", "r", stdin);

  x_points.reserve (LIMIT_COORD);
  y_points.reserve (LIMIT_COORD);
  for (int i = 0; i < NUM_SIDES_GIVEN; ++i) {
    int x, y;

    std::cin >> x >> y;
    if (x_points.find (x) == x_points.end ()) {
      x_points[x] = 1;
    } else {
      x_points[x]++;
    }
    if (y_points.find (y) == y_points.end ()) {
      y_points[y] = 1;
    } else {
      y_points[y]++;
    }
  }

  for (auto iter = x_points.begin (); iter != x_points.end (); ++iter) {
    if (iter->second == 1) {
      ans_x = iter->first;
    }
  }

  for (auto iter = y_points.begin (); iter != y_points.end (); ++iter) {
    if (iter->second == 1) {
      ans_y = iter->first;
    }
  }

  std::cout << ans_x << " " << ans_y << "\n";

  return 0;
}
