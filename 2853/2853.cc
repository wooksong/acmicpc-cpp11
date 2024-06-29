#include <iostream>

constexpr int MAX_NUM_DAYS = 5001;

int
main ()
{
  int days[MAX_NUM_DAYS] = {
    0,
  };
  int N;
  int init_day, ans;

  // freopen("input.txt", "r", stdin);
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> days[i];
  }

  init_day = days[0];
  ans = 0;
  for (int i = 1; i < N; ++i) {
    int diff;

    if (days[i] == 0)
      continue;

    diff = days[i] - init_day;
    ans++;

    for (int j = i; j < N; ++j) {
      if (days[j] == 0) {
        continue;
      }

      if ((days[j] % diff) == 1) {
        days[j] = 0;
      }
    }
  }

  std::cout << ans << "\n";
  return 0;
}
