#include <iostream>

int
main ()
{
  uint32_t T, streaks, score;

  // freopen("input.txt", "r", stdin);

  std::cin >> T;
  for (uint32_t i = 0; i < T; ++i) {
    std::string res;
    streaks = 0;
    score = 0;

    std::cin >> res;
    for (auto iter = res.begin (); iter != res.end (); ++iter) {
      if (*iter == 'O') {
        score += ++streaks;
        continue;
      }
      streaks = 0;
    }

    std::cout << score << "\n";
  }
  return 0;
}
