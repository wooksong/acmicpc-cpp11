#include <iostream>
#include <vector>

constexpr int MAX_NUM_TILES = 2001;
int tmp[MAX_NUM_TILES];

void merge (std::vector<int> &tiles, int idx_s, int idx_m, int idx_e);
void sort (std::vector<int> &tiles, int idx_s, int idx_e);

int
main ()
{
  std::vector<int> tiles_one;
  std::vector<int> tiles_two;
  int N, A, B, idx_one, idx_two;
  int ans;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N >> A >> B;

  tiles_one = std::vector<int> (A);
  tiles_two = std::vector<int> (B);

  for (int i = 0; i < A; ++i) {
    std::cin >> tiles_one[i];
  }

  for (int i = 0; i < B; ++i) {
    std::cin >> tiles_two[i];
  }
  sort (tiles_one, 0, A);
  sort (tiles_two, 0, B);

  ans = 0;
  idx_one = A - 1;
  idx_two = B - 1;
  while (N != 0) {
    int pick = 0;
    int step = 0;

    if (N == 1 || idx_two < 0) {
      pick = tiles_one[idx_one--];
      step = 1;
    } else {
      step = 2;
      pick = tiles_two[idx_two];

      if (idx_one >= 1 && ((tiles_one[idx_one] + tiles_one[idx_one - 1]) > pick)
          && (((N - 2) % 2 != 1) || (idx_one - 2) >= 0)) {
        pick = tiles_one[idx_one] + tiles_one[idx_one - 1];
        idx_one -= 2;
      } else {
        idx_two--;
      }
    }
    ans += pick;
    N -= step;
  }

  std::cout << ans << "\n";
}

void
merge (std::vector<int> &tiles, int idx_s, int idx_m, int idx_e)
{
  int i, j, pos;

  i = idx_s;
  pos = idx_s;
  j = idx_m;
  while (i < idx_m && j < idx_e) {
    if (tiles[i] < tiles[j]) {
      tmp[pos++] = tiles[i++];
    } else {
      tmp[pos++] = tiles[j++];
    }
  }

  while (i < idx_m) {
    tmp[pos++] = tiles[i++];
  }

  while (j < idx_e) {
    tmp[pos++] = tiles[j++];
  }

  for (i = idx_s; i < idx_e; ++i) {
    tiles[i] = tmp[i];
  }
}

void
sort (std::vector<int> &tiles, int idx_s, int idx_e)
{
  int idx_m;

  if ((idx_e - idx_s) < 2)
    return;

  idx_m = (idx_e - idx_s) / 2 + idx_s;

  sort (tiles, idx_s, idx_m);
  sort (tiles, idx_m, idx_e);
  merge (tiles, idx_s, idx_m, idx_e);
}
