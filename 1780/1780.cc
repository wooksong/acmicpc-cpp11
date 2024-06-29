#include <iostream>

constexpr int MAX_N = 2187;
constexpr int NUM_TVALS = 3;

int cnt[NUM_TVALS] = {
  0,
};
int mat[MAX_N][MAX_N];

void check (int r, int c, int n);
void count (int val);

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
      std::cin >> mat[i][j];
    }
  }

  check (0, 0, N);

  for (int i = 0; i < NUM_TVALS; ++i) {
    std::cout << cnt[i] << "\n";
  }

  return 0;
}

void
check (int r, int c, int n)
{
  int v;

  if (n == 1) {
    count (mat[r][c]);
    return;
  }

  for (v = -1; v < 2; ++v) {
    bool found = true;

    for (int i = r; i < r + n; ++i) {
      for (int j = c; j < c + n; ++j) {
        if (mat[i][j] != v) {
          found = false;
        }
      }
    }

    if (found) {
      break;
    }
  }

  if (v != (NUM_TVALS - 1)) {
    count (v);
    return;
  }

  n /= NUM_TVALS;
  for (int i = 0; i < NUM_TVALS; ++i) {
    for (int j = 0; j < NUM_TVALS; ++j) {
      check (r + i * n, c + j * n, n);
    }
  }
}

void
count (int val)
{
  switch (val) {
    case -1:
      cnt[0]++;
      break;
    case 0:
      cnt[1]++;
      break;
    case 1:
      cnt[2]++;
      break;
    default:
      break;
  }
}
