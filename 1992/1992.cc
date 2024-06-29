#include <iostream>
#include <vector>

uint64_t to_binary (std::string s);
void compress (std::vector<uint64_t> &piece, uint64_t col, uint64_t row, uint64_t len);

int
main ()
{
  std::vector<uint64_t> image;
  uint64_t N;

  // freopen("input.txt", "r", stdin);

  std::ios_base::sync_with_stdio (false);
  std::cin.tie (nullptr);
  std::cin >> N;

  for (uint64_t i = 0; i < N; ++i) {
    std::string line;

    std::cin >> line;
    image.push_back (to_binary (line));
  }

  compress (image, 0, 0, N);
  std::cout << "\n";
  return 0;
}

void
compress (std::vector<uint64_t> &piece, uint64_t col, uint64_t row, uint64_t len)
{
  uint64_t check = 0x1;
  bool found;
  uint64_t tmp;

  tmp = len;
  while (tmp > 1) {
    tmp--;
    check <<= 1;
    check |= 0x1;
  }
  check <<= col;

  tmp = row + len;
  found = true;
  for (uint64_t i = row; i < tmp; ++i) {
    if ((piece[i] & check) != check) {
      found = false;
    }
  }
  if (found) {
    std::cout << "1";
    return;
  }

  found = true;
  for (uint64_t i = row; i < tmp; ++i) {
    if ((~piece[i] & check) != check) {
      found = false;
    }
  }
  if (found) {
    std::cout << "0";
    return;
  }

  len /= 2;

  std::cout << "(";
  compress (piece, col + len, row, len);
  compress (piece, col, row, len);
  compress (piece, col + len, row + len, len);
  compress (piece, col, row + len, len);
  std::cout << ")";
}

uint64_t
to_binary (std::string s)
{
  uint64_t lshft = 0;
  uint64_t ret = 0x0;

  for (auto iter = s.rbegin (); iter != s.rend (); ++iter) {
    ret |= (static_cast<uint64_t> (*iter - '0') & 0x1) << lshft++;
  }

  return ret;
}
