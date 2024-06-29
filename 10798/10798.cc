#include <iostream>
#include <vector>

constexpr size_t NUM_STRS = 5;

int
main ()
{
  std::vector<std::string> strs (NUM_STRS);
  size_t max_len = 0;
  size_t pos;

  // freopen("input.txt", "r", stdin);

  for (size_t i = 0; i < NUM_STRS; ++i) {
    size_t len;

    std::getline (std::cin, strs[i]);
    len = strs[i].length ();
    max_len = (len > max_len ? len : max_len);
  }

  pos = 0;
  while (pos < max_len) {
    for (std::string cur_str : strs) {
      if (cur_str.length () <= pos) {
        continue;
      }

      std::cout << cur_str[pos];
    }
    pos++;
  }

  std::cout << "\n";

  return 0;
}
