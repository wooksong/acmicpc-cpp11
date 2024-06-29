#include <iostream>
#include <vector>

std::vector<int32_t> nums;
std::vector<int32_t> tmp;

void merge (size_t l, size_t m, size_t r);
void sort (size_t l, size_t r);
bool binary_search (size_t l, size_t r, int32_t val);

int
main ()
{
  size_t N, M;

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (NULL);

  // freopen("input.txt", "r", stdin);

  std::cin >> N;
  nums = std::vector<int32_t> (N);
  tmp = std::vector<int32_t> (N);
  for (size_t i = 0; i < N; ++i) {
    std::cin >> nums[i];
  }

  sort (0, N);

  std::cin >> M;
  for (size_t i = 0; i < M; ++i) {
    int32_t num;

    std::cin >> num;
    if (binary_search (0, N, num))
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }

  return 0;
}

void
merge (size_t l, size_t m, size_t r)
{
  size_t pos = l, i, j;

  i = l;
  j = m;
  while (i < m && j < r) {
    if (nums[i] < nums[j]) {
      tmp[pos++] = nums[i++];
    } else {
      tmp[pos++] = nums[j++];
    }
  }

  for (; i < m; ++i) {
    tmp[pos++] = nums[i];
  }
  for (; j < r; ++j) {
    tmp[pos++] = nums[j];
  }

  for (i = l; i < r; ++i) {
    nums[i] = tmp[i];
  }
}

void
sort (size_t l, size_t r)
{
  size_t m;

  if (r - l <= 1)
    return;

  m = (r - l) / 2 + l;
  sort (l, m);
  sort (m, r);
  merge (l, m, r);
}

bool
binary_search (size_t l, size_t r, int32_t val)
{
  size_t m;

  if ((r - l) == 1)
    return (nums[l] == val);

  m = (r - l) / 2 + l;
  if (nums[m] == val) {
    return true;
  } else if (nums[m] > val) {
    return binary_search (l, m, val);
  }

  return binary_search (m, r, val);
}
