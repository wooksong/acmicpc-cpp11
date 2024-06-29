#include <iostream>
#include <vector>

using map_t = std::vector<std::vector<int>>;

int num_cols, num_rows;
int max_sum = INT32_MIN;

map_t map;
map_t visited;

void dfs (int depth, int r, int c, int sum);
void traverse (int r, int c);

int
main ()
{
  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);

  std::cin >> num_rows >> num_cols;
  map = map_t (num_rows, std::vector<int> (num_cols));
  visited = map_t (num_rows, std::vector<int> (num_cols, 0));
  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_cols; ++j) {
      std::cin >> map[i][j];
    }
  }

  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_cols; ++j) {
      visited[i][j] = 1;
      dfs (0, i, j, map[i][j]);
      visited[i][j] = 0;
    }
  }
  for (int i = 0; i < num_rows; ++i) {
    for (int j = 0; j < num_cols; ++j) {
      traverse (i, j);
    }
  }

  std::cout << max_sum << "\n";

  return 0;
}

void
dfs (int depth, int r, int c, int sum)
{
  std::vector<std::pair<int, int>> d_move = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

  if (depth == 3) {
    max_sum = std::max (max_sum, sum);
    return;
  }

  for (auto d = d_move.begin (); d != d_move.end (); ++d) {
    int d_y = r + d->first;
    int d_x = c + d->second;

    if (d_y < 0 || d_y >= num_rows || d_x < 0 || d_x >= num_cols)
      continue;

    if (!visited[d_y][d_x]) {
      int new_sum = sum + map[d_y][d_x];

      visited[d_y][d_x] = 1;
      dfs (depth + 1, d_y, d_x, new_sum);
      visited[d_y][d_x] = 0;
    }
  }
}

void
traverse (int r, int c)
{
  std::vector<std::vector<std::pair<int, int>>> d_moves
      = { { { 0, 0 }, { 0, 1 }, { 0, 2 }, { -1, 1 } },
          { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },
          { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, -1 } },
          { { 0, 0 }, { 1, 0 }, { 2, 0 }, { 1, 1 } } };

  for (auto iter = d_moves.begin (); iter != d_moves.end (); ++iter) {
    int sum = 0;

    for (auto d = iter->begin (); d != iter->end (); ++d) {
      int d_y = r + d->first;
      int d_x = c + d->second;

      if (d_y < 0 || d_y >= num_rows || d_x < 0 || d_x >= num_cols)
        continue;
      sum += map[d_y][d_x];
    }

    max_sum = std::max (max_sum, sum);
  }
}
