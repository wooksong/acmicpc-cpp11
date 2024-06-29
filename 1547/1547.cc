#include <iostream>

constexpr int NUM_CUPS = 3;

int
main ()
{
  int cups[NUM_CUPS] = {
    1,
    0,
  };
  int M;
  int x, y;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  std::cin >> M;
  for (int i = 0; i < M; ++i) {
    std::cin >> x >> y;

    std::swap (cups[x - 1], cups[y - 1]);
  }

  for (int i = 0; i < NUM_CUPS; ++i) {
    if (cups[i]) {
      std::cout << i + 1 << "\n";
      break;
    }
  }

  return 0;
}
