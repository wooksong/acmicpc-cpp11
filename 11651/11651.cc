#include <algorithm>
#include <iostream>
#include <vector>

constexpr int32_t INVALID_VAL = -100001;
struct Point {
  int32_t x;
  int32_t y;

  Point ()
  {
    this->x = INVALID_VAL;
    this->y = INVALID_VAL;
  }
  Point (int32_t x, int32_t y)
  {
    this->x = x;
    this->y = y;
  };

  friend bool operator<(Point l, Point r);
  friend bool operator> (Point l, Point r);
};

int
main ()
{
  uint32_t N;
  std::vector<Point> points;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;
  for (uint32_t i = 0; i < N; ++i) {
    Point tmp;

    std::cin >> tmp.x >> tmp.y;
    points.push_back (tmp);
  }

  std::sort (points.begin (), points.end ());
  for (auto &p : points) {
    std::cout << p.x << " " << p.y << "\n";
  }

  return 0;
}

bool
operator<(Point l, Point r)
{
  if (l.y < r.y)
    return true;
  if (l.y == r.y)
    return (l.x < r.x);
  return false;
}

bool
operator> (Point l, Point r)
{
  return !(l < r);
}
