#include <iostream>
#include <vector>

constexpr int UPPER_BOUND = 999;
constexpr int LOWER_BOUND = -999;

int
main ()
{
  std::vector<std::pair<int, int>> x_y_pairs;
  int eq1_coef1, eq1_coef2, eq1_rhs;
  int eq2_coef1, eq2_coef2, eq2_rhs;
  int x, y;

  // freopen("input.txt", "r", stdin);

  std::cin >> eq1_coef1 >> eq1_coef2 >> eq1_rhs;
  std::cin >> eq2_coef1 >> eq2_coef2 >> eq2_rhs;

  if (eq1_coef1 == 0) {
    y = eq1_rhs / eq1_coef2;
    x = (eq2_rhs - eq2_coef2 * y) / eq2_coef1;
  } else if (eq1_coef2 == 0) {
    x = eq1_rhs / eq1_coef1;
    y = (eq2_rhs - eq2_coef1 * x) / eq2_coef2;
  } else if (eq2_coef1 == 0) {
    y = eq2_rhs / eq2_coef2;
    x = (eq1_rhs - eq1_coef2 * y) / eq1_coef1;
  } else if (eq2_coef2 == 0) {
    x = eq2_rhs / eq2_coef1;
    y = (eq1_rhs - eq1_coef1 * x) / eq1_coef2;
  } else {
    for (int x = LOWER_BOUND; x <= UPPER_BOUND; ++x) {
      int by = eq1_rhs - x * eq1_coef1;

      if (by % eq1_coef2 != 0)
        continue;
      x_y_pairs.push_back ({ x, by / eq1_coef2 });
    }
    for (std::pair<int, int> x_y_pair : x_y_pairs) {
      if ((x_y_pair.first * eq2_coef1 + x_y_pair.second * eq2_coef2) == eq2_rhs) {
        x = x_y_pair.first;
        y = x_y_pair.second;
        break;
      }
    }
  }
  std::cout << x << " " << y << "\n";
  return 0;
}
