#include <iostream>

int
main ()
{
  int N, K, cnt;

  // freopen("input.txt", "r", stdin);

  std::cin >> N >> K;
  cnt = 0;
  for (int h = 0; h <= N; ++h) {
    for (int m = 0; m < 60; ++m) {
      for (int s = 0; s < 60; ++s) {
        if (((h % 10) == K) || ((h / 10) == K)) {
          cnt++;
        } else if (((m % 10) == K) || ((m / 10) == K)) {
          cnt++;
        } else if (((s % 10) == K) || ((s / 10) == K)) {
          cnt++;
        }
      }
    }
  }

  std::cout << cnt << "\n";

  return 0;
}
