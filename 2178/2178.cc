#include <deque>
#include <iostream>
#include <vector>

constexpr int NUM_MOVES = 4;
enum Coord {
  Y = 0,
  X = 1,
  NUM_COORDS,
};

std::pair<int, int> moves[NUM_MOVES] = {
  { -1, 0 },
  { 1, 0 },
  { 0, -1 },
  { 0, 1 },
};

int bfs (std::vector<std::vector<int>> &m, std::vector<std::vector<int>> &steps,
    int num_rows, int num_cols);

int
main ()
{
  std::vector<std::vector<int>> map;
  std::vector<std::vector<int>> steps;
  int N, M;

  // freopen("input.txt", "r", stdin);
  std::cin >> N >> M;

  map = std::vector<std::vector<int>> (N);
  steps = std::vector<std::vector<int>> (N);
  for (auto iter = steps.begin (); iter != steps.end (); ++iter) {
    *iter = std::vector<int> (M, -1);
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char c;

      std::cin >> c;
      map[i].push_back (static_cast<int> (c - '0'));
    }
  }
  std::cout << bfs (map, steps, N, M) << "\n";

  return 0;
}

int
bfs (std::vector<std::vector<int>> &m, std::vector<std::vector<int>> &steps,
    int num_rows, int num_cols)
{
  std::deque<std::pair<int, int>> queue;
  int s_y, s_x;

  s_y = 0;
  s_x = 0;
  steps[s_y][s_x] = 1;

  queue.push_back ({ s_y, s_x });
  while (!queue.empty ()) {
    std::pair<int, int> p = queue.front ();

    queue.pop_front ();
    for (std::pair<int, int> dm : moves) {
      int y, x;

      y = p.first + dm.first;
      x = p.second + dm.second;

      if (y < 0 || y >= num_rows || x < 0 || x >= num_cols)
        continue;

      if (m[y][x] != 1)
        continue;

      if (steps[y][x] == -1) {
        steps[y][x] = steps[p.first][p.second] + 1;
        queue.push_back ({ y, x });
      }
    }
  }

  return steps[num_rows - 1][num_cols - 1];
}
