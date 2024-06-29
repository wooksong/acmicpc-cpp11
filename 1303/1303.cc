#include <deque>
#include <iostream>
#include <vector>

enum Direction {
  UP = 0,
  DOWN = 1,
  LEFT = 2,
  RIGHT = 3,
  NUM_DIRECTIONS,
};

constexpr int MAX_NUM_ROWS = 101;
constexpr int MAX_NUM_COLS = 101;

char map[MAX_NUM_ROWS][MAX_NUM_COLS];
bool visited[MAX_NUM_ROWS][MAX_NUM_COLS];
std::pair<int, int> move[NUM_DIRECTIONS];

size_t bfs (char s, int r, int c, int M, int N);

int
main ()
{
  int N, M;
  size_t b_power, w_power;

  move[UP] = { -1, 0 };
  move[DOWN] = { 1, 0 };
  move[LEFT] = { 0, -1 };
  move[RIGHT] = { 0, 1 };

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);

  // freopen("input.txt", "r", stdin);

  std::cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> map[i][j];
      visited[i][j] = false;
    }
  }

  b_power = 0;
  w_power = 0;
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      size_t power;

      if (visited[i][j])
        continue;

      power = bfs (map[i][j], i, j, M, N);
      if (map[i][j] == 'B') {
        b_power += power;
      } else {
        w_power += power;
      }
    }
  }

  std::cout << w_power << " " << b_power << "\n";

  return 0;
}

size_t
bfs (char s, int r, int c, int n_rows, int n_cols)
{
  std::deque<std::pair<int, int>> q;
  size_t ret;

  q.push_back (std::make_pair (r, c));

  ret = 0;
  while (!q.empty ()) {
    int cur_r, cur_c;

    std::pair<int, int> coord = q.front ();
    q.pop_front ();

    cur_r = coord.first;
    cur_c = coord.second;

    visited[cur_r][cur_c] = true;
    ret++;

    // Up/Down/Left/Right
    for (int i = 0; i < NUM_DIRECTIONS; ++i) {
      int next_r = cur_r + move[i].first;
      int next_c = cur_c + move[i].second;

      if (next_r < 0 || next_r >= n_rows || next_c < 0 || next_c >= n_cols)
        continue;

      if (!visited[next_r][next_c] && map[next_r][next_c] == s) {
        visited[next_r][next_c] = true;
        q.push_back (std::make_pair (next_r, next_c));
      }
    }
  }
  return (ret * ret);
}
