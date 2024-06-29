#include <iostream>

constexpr size_t MAX_LEN = 1001;

int
main ()
{
  std::string str;
  size_t pos;
  char letter;

  // freopen("input.txt", "r", stdin);
  std::cin.tie (nullptr);
  std::cout.tie (nullptr);

  str.reserve (MAX_LEN);
  std::cin >> str;
  std::cin >> pos;

  letter = str[pos - 1];
  std::cout << letter << "\n";

  return 0;
}
