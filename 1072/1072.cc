#include <iostream>
struct info_t {
  uint64_t num_wins = 0;
  uint64_t num_games = 0;
  uint64_t ratio = 0;
};

uint64_t ans = UINT64_MAX;

void binary_search (info_t &games, uint64_t s, uint64_t e);
int
main ()
{
  info_t game_info;

  // freopen("input.txt", "r", stdin);
  std::cin >> game_info.num_games >> game_info.num_wins;
  game_info.ratio = game_info.num_wins * 100 / game_info.num_games;
  binary_search (game_info, 1, 1000000000LU);
  if (ans == UINT64_MAX) {
    std::cout << "-1\n";
  } else {
    std::cout << ans << "\n";
  }

  return 0;
}

void
binary_search (info_t &games, uint64_t s, uint64_t e)
{
  uint64_t m = (e + s) / 2;
  uint64_t new_games, new_wins, new_ratio;

  if (e < s) {
    return;
  }

  new_games = games.num_games + m;
  new_wins = games.num_wins + m;
  new_ratio = new_wins * 100 / new_games;

  if (games.ratio != new_ratio) {
    ans = std::min (ans, m);
    binary_search (games, s, m - 1);
  } else if (games.ratio == new_ratio) {
    binary_search (games, m + 1, e);
  }
}
