#include <iostream>
#include <vector>

constexpr int LEN_MAT = 9;

int
main ()
{
  std::vector<std::vector<int>> mat (LEN_MAT, std::vector<int> (LEN_MAT));
  int r, c;
  int max_val = INT32_MIN;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  for (int i = 0; i < LEN_MAT; ++i) {
    for (int j = 0; j < LEN_MAT; ++j) {
      std::cin >> mat[i][j];
      if (mat[i][j] > max_val) {
        r = i + 1;
        c = j + 1;
        max_val = mat[i][j];
      }
    }
  }

  std::cout << max_val << "\n";
  std::cout << r << " " << c << "\n";

  return 0;
}
