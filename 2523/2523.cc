#include <iostream>

int
main ()
{
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> N;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  for (int i = 0; i < N; ++i) {
    std::cout << "*";
  }
  std::cout << "\n";
  for (int i = N - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  return 0;
}
