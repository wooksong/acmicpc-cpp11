#include <iostream>

int
main ()
{
  uint32_t T;

  // freopen("input.txt", "r", stdin);
  std::cin >> T;
  for (uint32_t i = 0; i < T; ++i) {
    std::string str;
    uint32_t r;

    std::cin >> r >> str;
    for (auto iter = str.begin (); iter != str.end (); ++iter) {
      for (uint32_t j = 0; j < r; ++j) {
        printf ("%c", *iter);
      }
    }
    printf ("\n");
  }
  return 0;
}
