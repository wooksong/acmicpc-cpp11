#include <iostream>

int
main ()
{
  int N;
  int num_stars;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;
  num_stars = 2 * N - 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      std::cout << ' ';
    }
    for (int j = 0; j < num_stars; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
    num_stars -= 2;
  }

  return 0;
}
