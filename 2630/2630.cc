#include <iostream>

constexpr int MAX_N = 128;

enum Color {
  WHITE = 0,
  BLUE = 1,
  NUM_COLORS,
};

int paper[MAX_N][MAX_N];
int cnt[NUM_COLORS];

void divide (int r, int c, int n);

int
main ()
{
  int N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cin >> paper[i][j];
    }
  }

  divide (0, 0, N);

  for (int i = 0; i < NUM_COLORS; ++i) {
    std::cout << cnt[i] << "\n";
  }

  return 0;
}

void
divide (int r, int c, int n)
{
  int rn, cn;
  int color;
  bool found;

  if (n == 1) {
    cnt[paper[r][c]]++;
    return;
  }

  rn = r + n;
  cn = c + n;
  for (color = WHITE; color < NUM_COLORS; ++color) {
    found = true;

    for (int i = r; found && i < rn; ++i) {
      for (int j = c; j < cn; ++j) {
        if (paper[i][j] != color) {
          found = false;
          break;
        }
      }
    }

    if (found) {
      cnt[color]++;
      return;
    }
  }

  n /= 2;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      divide (r + i * n, c + j * n, n);
    }
  }
}
