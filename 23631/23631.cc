#include <iostream>

constexpr int MAX_VAL_E = 5000;

int
main ()
{
  int T;

  // freopen("input.txt", "r", stdin);
  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    long long N, K, need, left, right, now;

    std::cin >> N >> K;

    now = -1;
    need = N - 1;
    left = 0;
    right = MAX_VAL_E;

    while (left <= right) {
      long long mid = (left + right) / 2;

      if (K * mid * (mid + 1) / 2 <= need) {
        left = mid + 1;
        now = mid;
      } else {
        right = mid - 1;
      }
    }

    if (now % 2) {
      std::cout << (now / 2 + 1) * K - (need - K * now * (now + 1) / 2) << " L\n";
    } else {
      std::cout << -(now / 2) * K + (need - K * now * (now + 1) / 2) << " R\n";
    }
  }

  return 0;
}
